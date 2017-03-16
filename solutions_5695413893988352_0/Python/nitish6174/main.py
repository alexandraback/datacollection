from math import *

t = int(input())

for itr in range(0,t):
	line = (input()).split(' ')
	s1 = list(line[0])
	s2 = list(line[1])
	l = len(s1)
	case = 0
	for i in range(0,l):
		if s1[i]=='?' and s2[i]=='?':
			if case==0:
				s1[i] = 0
				s2[i] = 0
			elif case==1:
				s1[i] = 0
				s2[i] = 9
			elif case==2:
				s1[i] = 9
				s2[i] = 0
		elif s1[i]=='?' and not(s2[i]=='?'):
			if case==0:
				s1[i] = s2[i]
			elif case==1:
				s1[i] = 0
			elif case==2:
				s1[i] = 9
		elif not(s1[i]=='?') and s2[i]=='?':
			if case==0:
				s2[i] = s1[i]
			elif case==1:
				s2[i] = 9
			elif case==2:
				s2[i] = 0
		elif case==0:
			if int(s1[i])>int(s2[i]):
				case = 1
			elif int(s1[i])<int(s2[i]):
				case = 2

	for i in range(0,l):
		s1[i] = str(s1[i])
		s2[i] = str(s2[i])
	s1 = ''.join(s1)
	s2 = ''.join(s2)
	print("Case #"+str(itr+1)+": "+s1+" "+s2)
