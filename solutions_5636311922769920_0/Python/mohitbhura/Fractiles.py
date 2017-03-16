# Fractiles.py

t = int(raw_input())
for x in xrange(1,t+1):
	k,c,s = map(int,raw_input().split())
	ans = ''
	for i in xrange(1,k+1):
		ans += str(i)+' ';
	print 'Case #'+str(x)+':',str(ans);