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
			
def blahsolve(a,m):
	bestans=[len(m),0] #remove all
	for i in range(len(m)+1):
		#absorb 0..i, remove i+1..len(m)-1
		size=a
		added=0
		for ii in range(i+1):
			while size <= m[ii]:
				size += size-1 #add mote of size size-1
				added += 1
			size += m[ii]
		alt=[len(m)-i-1,added]
		if sum(bestans)>sum(alt): bestans=alt
	return bestans

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
