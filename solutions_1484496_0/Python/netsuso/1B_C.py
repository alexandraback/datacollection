#!/usr/bin/python3

import sys

# Ignore the number of cases
sys.stdin.readline()

def print_array(numset):
	res=""
	for n in numset:
		res += "%d " % n
	print(res)

casenum = 0
for line in sys.stdin:
	casenum += 1

	data = line.strip().split(' ')
	total = int(data[0])
	nums = data[1:]
	for i in range(0, total):
		nums[i] = int(nums[i])

	sums = {}
	print("Case #%d:" % (casenum))

	found = False
	for i in range(0, total):
		numi = nums[i]
		setsum = numi
		setcomponents = [numi]
		if setsum in sums:
			print_array(sums[setsum])
			print_array(setcomponents)
			found = True
			break
		sums[setsum] = setcomponents

		for j in range(i+1, total):
			numj = nums[j]
			setsum = numi + numj
			setcomponents = [numi, numj]
			if setsum in sums:
				print_array(sums[setsum])
				print_array(setcomponents)
				found = True
				break
			sums[setsum] = setcomponents

			for k in range(j+1, total):
				numk = nums[k]
				setsum = numi + numj + numk
				setcomponents = [numi, numj, numk]
				if setsum in sums:
					print_array(sums[setsum])
					print_array(setcomponents)
					found = True
					break
				sums[setsum] = setcomponents

			if found: break

		if found: break

	if not found:
		print("Impossible")
