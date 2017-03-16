
# BINARY SEARCH
def find(n):
	lo,hi = 0,len(fs)-1
	if fs[lo] >= n: return lo
	if fs[hi] <= n: return hi
	
	while hi-lo>1:
		mi = (lo+hi)/2
		if fs[mi]<n: lo=mi
		elif fs[mi]>n: hi=mi
		else: return mi
	return hi
		
if __name__ == "__main__":
	N = 1000
	fair = [i for i in xrange(1,int(N**.5)+1) if str(i)==str(i)[::-1]]
	fs = [i**2 for i in fair if str(i**2)==str(i**2)[::-1]]
	fin = open('C-small-attempt1.in', 'r').readlines()
	fout = open('C-small-attempt1.out', 'wb')
	T = int(fin[0].strip())
		
	for i in xrange(1,T+1):
		[lo,hi] = [int(x) for x in fin[i].strip().split(' ')]
		l,h = find(lo), find(hi)
		if fs[l]<lo: l+=1
		if fs[h]>hi: h-=1
		fout.write('Case #{}: {}\n'.format(i, h-l+1))