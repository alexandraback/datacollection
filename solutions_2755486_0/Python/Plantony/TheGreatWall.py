#!C:\Python33\python
import sys
import fileinput
import bisect
from collections import *

sys.path.append(r'D:\Data\Programming\Code Jam\Libraries')
from CodeJamLib import *
class Attack:
	day = None
	attacksLeft = None
	west = None
	east = None
	strength = None
	dayModifier = None
	distanceModifier = None
	strengthModifier = None
	def __init__ (self, day, attacksLeft, west, east, strength, dayModifier, distanceModifier, strengthModifier):
		self.day = day
		self.attacksLeft = attacksLeft
		self.west = west
		self.east = east
		self.strength = strength
		self.dayModifier = dayModifier
		self.distanceModifier = distanceModifier
		self.strengthModifier = strengthModifier
	
def main ():
	lines = fileinput.input()
	cases = int(lines.readline())
	for case in range(1, cases + 1):
		tribes = readInts(lines.readline())[0]
		attacks = []
		for tribe in range(tribes):
			day, attacksLeft, west, east, strength, dayModifier, distanceModifier, strengthModifier = readInts(lines.readline())
			attacks.append(Attack(day, attacksLeft, west, east, strength, dayModifier, distanceModifier, strengthModifier))
		
		print ("Case #{0}: {1}".format(case, getGoodAttacks(attacks)))

def getGoodAttacks(attacks):
	attacks.sort(key = lambda t: t.day)
	wall = {}
	goodCount = 0
	lastRepair = -1
	while len(attacks) > 0:	
		good = False
		attack = attacks.pop(0)
		
		if lastRepair < attack.day:
			lastRepair = attack.day
			for point in wall:
				wall[point] = [wall[point][1], wall[point][1]]
			
		for point in generatePoints(attack.west, attack.east):
			if point not in wall:
				wall[point] = [0, 0]
			
			if wall[point][0] < attack.strength:
				good = True
				wall[point][1] = max(wall[point][1], attack.strength)
		
		if good:
			goodCount += 1
			
		if attack.attacksLeft > 1:
			newAttack = Attack(attack.day + attack.dayModifier, attack.attacksLeft - 1, attack.west + attack.distanceModifier, attack.east + attack.distanceModifier, 
			attack.strength + attack.strengthModifier, attack.dayModifier, attack.distanceModifier, attack.strengthModifier)
			
			attacks.insert(bisect.bisect_left([a.day for a in attacks], newAttack.day), newAttack)
			
			
		
	return goodCount

def generatePoints(start, end):
	for i in range(start, end + 1):
		yield i
		if i != end:
			yield i + 0.5
main()