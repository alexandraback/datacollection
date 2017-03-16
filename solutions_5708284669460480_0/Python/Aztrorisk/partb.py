from Library import *
import math

def checkrepeat(target, i):
	for j in range(len(target)):
		if i + j == len(target):
			return True # you can repeat
		if (target[j] != target[i + j]):
			return False
	return True

def calmin(k, target, s):
	if (s < len(target)):
		return 0
	n = target
	repeatable = False
	repeatn = 0
	for i in range(len(target)):
		if k[ord("Z") - ord(target[i])] == 0:
			return 0 # impossible to type such word
	for i in range(len(target)):
		if i != 0:
			if target[i] == target[0]:
				if checkrepeat(target, i):
					repeatable = True
					repeatn = i
					break
	if (repeatable):
		r = s - len(target)
		return 1 + int(r / i)
	else:
		return int(s / len(target))

def calexp(k, target, s, knum):
	probword = 1
	for i in range(len(target)):
		pletter = k[ord("Z") - ord(target[i])] / float(knum)
		probword *= pletter
	return probword * (1 + s - len(target))

def solve(keys, target, s):
	k = [0 for i in range(26)]
	for i in range(len(keys)):
		n = ord("Z") - ord(keys[i])
		k[n] += 1
	minbananas = calmin(k, target, s)
	if (minbananas == 0):
		return 0
	expected = calexp(k, target, s, len(keys))
	return float(minbananas) - expected

lines = getLines("b.in")
out = []

for i in range(int(lines[0])):

	values = [int(l) for l in lines[i * 3 + 1].split()]
	keys = lines[i * 3 + 2].strip()
	target = lines[i * 3 + 3].strip()
	res = solve(keys, target, values[2])

	out.append("Case #%d: %.9f"%(i + 1, res))
writeOutLines("out.txt", out)