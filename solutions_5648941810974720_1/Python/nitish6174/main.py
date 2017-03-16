from math import *
import re

t = int(input())

for itr in range(0,t):
	s = input()
	count = [0]*10
	count[0] = s.count('Z')
	count[2] = s.count('W')
	count[4] = s.count('U')
	count[6] = s.count('X')
	count[8] = s.count('G')
	count[1] = s.count('O') - (count[0]+count[2]+count[4])
	count[3] = s.count('H') - (count[8])
	count[5] = s.count('F') - (count[4])
	count[7] = s.count('V') - (count[5])
	count[9] = s.count('I') - (count[5]+count[6]+count[8])	
	print("Case #"+str(itr+1)+": ",end="")
	for i in range(0,10):
		for j in range(0,count[i]):
			print(i,end="")
	print("")