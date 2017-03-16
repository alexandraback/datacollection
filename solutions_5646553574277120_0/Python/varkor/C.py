inputData = open("C.in", "r")
outputData = open("C.out", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))


def attempt (coins, add, target):
	rems = [target - add]
	for c in coins:
		if add + c == target:
			return [0]
		elif add + c < target:
			nc = list(coins)
			nc.remove(c)
			rems += attempt(nc, add + c, target)
	return rems

from fractions import gcd
from functools import reduce

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 2 == 0:
		(C, D, value) = map(int, line.split(" "))
	else:
		coins = list(map(int, line.split(" ")))
		rems = []
		for i in range(1, value):
			vv = attempt(coins, 0, i)
			if 0 not in vv:
				rems.append(list(set(vv)))
		denoms = 0
		print(value, coins, rems)
		while len(rems) > 0:
			common = {}
			for x in rems:
				for v in x:
					if str(v) in common:
						common[str(v)] += 1
					else:
						common[str(v)] = 1
			comm = []
			for h in common:
				comm.append(int(h))
			comm = list(set(comm))
			delet = min(comm)
			denoms += 1
			dels = 0
			for (ii, x) in enumerate(list(rems)):
				if delet in x:
					del rems[ii - dels]
					dels += 1
		case(number // 2 + 1, denoms)


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()