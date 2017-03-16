from itertools import permutations
import fileinput
from math import factorial

lines = iter(fileinput.input())

T = eval(next(lines))

dataInd = 0
for i in range(1, T+1):
	dataInd += 1
	N = eval(next(lines))
	strs = next(lines).split()
	letters = []
	for s in strs:
		sLetters = set([])
		for a in s:
			if(a not in sLetters):
				sLetters.add(a)
		letters.append(sLetters)

	groups = []
	groupLetters = []
	notgrouped = [True for x in range(N)]
	for j in range(len(letters)):
		if(notgrouped[j]):
			jgroup = [strs[j]]
			changed = True
			while(changed):
				changed = False
				for k in range(j+1, len(letters)):
					if(letters[j].intersection(letters[k]) and notgrouped[k]):
						jgroup.append(strs[k])
						letters[j].update(letters[k])
						changed = True
						notgrouped[k] = False
			groups.append(jgroup)
			groupLetters.append(letters[j])


	mult = factorial(len(groups))
	for g in groups:
		perms = permutations(g)
		count = 0
		for x in perms:
			train = "".join(x)
			letterPos = {}
			ind = -1
			valid = True
			for l in train:
				ind+=1
				if l in letterPos:
					if letterPos[l] != ind-1:
						valid = False
						break;
				letterPos[l] = ind
			if valid:
				count+=1
		mult*=count
	print("Case #" + str(i) + ": " + str(mult))
