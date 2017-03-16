#!/usr/bin/python
import sys
f = open('c.in')
T = int(f.readline())
for n in range(T):
	N = int(f.readline())
	s = f.readline().split()
	forward={}
	backward={}
	for j in range(len(s)):
		forward[j+1] = int(s[j])
		if int(s[j]) in backward:
			backward[int(s[j])].append(j+1)
		else:
			backward[int(s[j])] = [j+1]
	maxCount = 0
	for i in range(len(s)):
		l=[]
		forward_count = 1
		backward_count = 0
		prev = None
		cur = i+1
		l.append(i+1)
		while True:
			cur = forward[cur]
			l.append(cur)
			forward_count += 1
			if forward[cur] == l[0]:
				break
			elif forward[cur] == prev:
				maxList=[]
				prev = cur
				for j in range(len(s)):
					if j+1 in l:
						continue
					l2=[]
					c=1
					cur=j+1
					l2.append(cur)
					while True:
						if forward[cur] == prev:
							c = 0
							break
						elif forward[cur] == l[-1]:
							break
						elif forward[cur] in l or forward[cur] in l2:
							c = 0
							break
						else:
							prev = cur
							cur = forward[cur]
							l2.append(cur)
							c += 1
					if c > backward_count:
						backward_count = c
						l2.reverse()
						maxList = list(l2)
				if backward_count > 0:
					l.extend(maxList)
				break
			elif forward[cur] in l:
				forward_count = 0
				break
			else:
				prev = cur
		maxCount = max(maxCount,len(l))
#		print maxCount,l
	print 'Case #'+str(n+1)+": "+str(maxCount)
