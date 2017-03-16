
R=0

def solve(evns, eng):
	#print 'R',R
	if len(evns)==1:
		return evns[0]*eng
	maxGain=0
	for i in xrange(0, eng+1):
		nEng=max(0, min(eng,eng-i+R))
		curGain= evns[0]*i + solve(evns[1:], nEng)
		maxGain=max(maxGain, curGain)
		#print 'i,curGain,maxGain', i, curGain, maxGain
	#print 'eng, maxGain', maxGain
	return maxGain
	
def main():	
	global R
	T=input()
	for c in xrange(T):
		E,R,N = map(int, raw_input().split())
		evns = map(int, raw_input().split())
		
		ans= solve(evns, E)
		#print 'ans',ans
		print "Case #%d: %d" % (c+1, ans)
		#return

main()