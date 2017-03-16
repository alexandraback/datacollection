#!/usr/bin/python

T = int(raw_input())
for case in range(1,T+1):
	strings=raw_input().split(" ")
	A=int(strings[0])
	N=int(strings[1])
	motes=sorted(map(lambda x:int(x),raw_input().split(" ")))
	i=0
	nmote=A
	noop=0
	ops=0
	while True:
		if(nmote > motes[i]):
			nmote = nmote + motes[i]
			i=i+1
		else:
			ops = ops+1
			if(i==(len(motes)-1)):
					noop
					break
			else:
				if(nmote>1):
					nmote = nmote*2 - 1
				else:
					i=i+1
		if(ops>N):
			ops=N
			break;
		if(i==len(motes)):
			break;
	print "Case #"+str(case)+": "+str(ops) 
		

						
					
	

