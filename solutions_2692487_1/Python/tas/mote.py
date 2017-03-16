import sys


def solve(a,m):
	assert a > 0
	bestsol=[0,len(m)] #best soln so far #can remove all
	added=0 #number added
	for i in range(len(m)):
		if a > m[i]:
			# just absorb
			a += m[i]
		else:
			#consider discarding remainder
			alt = len(m)-i+added
			if alt < bestsol[0]+bestsol[1]: bestsol=[added,len(m)-i]
			#add until we can absorb
			if a > 1:
				while a <= m[i]:
					a += a-1 #add one of size a-1
					added += 1
				a += m[i]
			else:
				added = 100*len(m) #can't win by adding
	#if we get here we have added enough to absorb all
	if bestsol[0]+bestsol[1] > added: bestsol=[added,0]
	return bestsol
			
cases=int(sys.stdin.readline())
for case in range(cases):
	line=sys.stdin.readline().split()
	assert len(line)==2
	a=int(line[0])
	n=int(line[1])
	line=sys.stdin.readline().split()
	assert len(line)==n
	m=[int(x) for x in line]
	m.sort()
	sys.stderr.write('a='+str(a)+' m='+str(m))
	ans = solve(a, m)
	sys.stderr.write(' ans='+str(ans)+'\n')
	print 'Case #'+str(case+1)+': '+str(ans[0]+ans[1])
