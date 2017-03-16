from collections import defaultdict

class Tribe:
	__slots__=('firstDay', 'numAttacks', 'firstW', 'lenW', 'firstS', 'dd', 'dw', 'ds')
	def __init__(self, firstDay, numAttacks, firstW, firstE, firstS, dd, dw, ds):
		self.firstDay = firstDay
		self.numAttacks = numAttacks
		self.firstW = firstW
		self.lenW = firstE - firstW + 1
		self.firstS = firstS
		self.dd = dd
		self.dw = dw
		self.ds = ds

	def isDone(self, day):
		return self.attackNum(day) >= self.numAttacks
	
	def isAttacking(self, day):
		return day >= self.firstDay and (day - self.firstDay) % self.dd == 0 and self.attackNum(day) < self.numAttacks
	
	def attackNum(self, day):
		return (day - self.firstDay) // self.dd

	def strength(self, day):
		return self.firstS + (self.ds * self.attackNum(day))
	
	def west(self, day):
		return self.firstW + (self.dw * self.attackNum(day))
	
	def east(self, day):
		return self.west(day) + self.lenW - 1

def simulate(tribes):
	successes = 0
	day = -1
	wall = defaultdict(int)
	while True:
		day += 1
		flag = False
		for tribe in tribes:
			if not tribe.isDone(day):
				flag = True
				break

		if not flag:
			break

		best = defaultdict(int)
		for tribe in tribes:
			if tribe.isAttacking(day):
				flag = False
				for p in range(tribe.west(day), tribe.east(day)+1):
					if (p == tribe.west(day) or p < tribe.east(day)):
						best[p] = max(best[p], wall[p], tribe.strength(day))
						if (tribe.strength(day) > wall[p] and not flag):
							successes += 1
							flag = True

		for p in best.keys():
			wall[p] = best[p]
	return successes

tests = int(input())
for i in range(1, tests+1):
	numTribes = int(input())
	tribes = []
	for t in range(numTribes):
		arr = input().split(" ")
		tribe = Tribe(int(arr[0]), int(arr[1]), int(arr[2]), int(arr[3]), int(arr[4]), int(arr[5]), int(arr[6]), int(arr[7]))
		tribes.append(tribe)
	print("Case #" + str(i) + ": " + str(simulate(tribes)))
