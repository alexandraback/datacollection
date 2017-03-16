from math import *
lines = open('input.txt','r').readlines()
scores = []
surprisings = []
for s in range(31):
	possible = []	
	surp = []
	for a in range(max(int(ceil((s-4.0)/3)),0), int(floor(s/3.0))+1):
		for b in range(a,min(a+3,11)):
			for c in range(b,min(a+3,11)):
				if s == a + b + c:
					possible.append((a,b,c))
					if (c == a + 2):
						surp.append((a,b,c))
	scores.append(possible)
	surprisings.append(surp)
T = int(lines[0])
for i in range(1,T+1):
	line = lines[i].strip()
	arr = line.split()
	N = int(arr[0])
	S = int(arr[1])
	p = int(arr[2])
	t = []
	for j in range(N):
		t.append(int(arr[3+j]))
	t = sorted(t)
	res = 0
	done = set()
	for k in range(0, 11-p):
		for j in range(N):			
			if (len(surprisings[t[j]])) > 0 and not done.__contains__(j):
				if surprisings[t[j]][0][2] == p + k and S > 0:
					S = S - 1
					res = res + 1
					#print t[j], surprisings[t[j]][0]
					done.add(j)
	for j in range(N):
		if done.__contains__(j):
			continue
		if (scores[t[j]][-1][2] >= p):
			res += 1
			#print t[j], scores[t[j]][-1]
	print "Case #" + str(i) + ": "+ str(res)