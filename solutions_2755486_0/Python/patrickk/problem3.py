import math
f = open("in.txt")
T = int(f.readline())

w = open("out.txt", "w")

class Tribe:
	def __init__(self, line):
		self.day1, self.nrofattacks, self.west1, self.east1, self.strength1, self.deltadays, self.deltadistance, self.deltastrength = map(int, line.split())
		self.west1 += 100
		self.east1 += 100

	def getAttacks(self):
		attacks = []
		west, east = self.west1, self.east1
		day = self.day1
		strength = self.strength1
		for i in range(self.nrofattacks):
			attacks.append((day, (west, east, strength)))
			day += self.deltadays
			west += self.deltadistance
			east += self.deltadistance
			strength += self.deltastrength
		return attacks

def solveTestcase():
	global i
	N = int(f.readline())
	tribes = []
	wall = [0] * 3000
	timeline = [[] for j in xrange(676061)]
	lastday = 0
	for j in range(N):
		tribes.append(Tribe(f.readline()))
		attacks = tribes[j].getAttacks()
		for attack in attacks:
			timeline[attack[0]].append(attack[1])
			lastday = max(lastday, attack[0])

	#run attacks
	loses = 0
	for j in range(lastday + 1):
		updates = []
		for attack in timeline[j]:
			success = False
			for k in range(attack[0], attack[1]):
				if wall[k] < attack[2]:
					updates.append((k, attack[2]))
					success = True
			if success:
				loses += 1
		for update in updates:
			wall[update[0]] = update[1]

	w.write("Case #" + str(i + 1) + ": " + str(loses) + "\n")
	return None

for i in range(T):
	solveTestcase()