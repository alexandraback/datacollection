#!/usr/bin/env python3

def doprob():
	smax, data = input().split()
	smax = int(smax)
	data = [int(c) for c in data]
	standing, extra = 0, 0
	for shyness, num in enumerate(data):
		if shyness > standing:
			invite = shyness - standing
			extra += invite
			standing += invite
		
		standing += num
	
	return extra

ncases = int(input())
for caseno in range(1, ncases+1):
	answer = doprob()
	print('Case #%d:' % caseno, answer)