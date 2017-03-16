# Revenge of the Pancakes.py

def solve(s):

	ans = 0;
	while True:
		if '-' not in s :
			print 'Case #'+str(x)+':',str(ans);
			return;
		ans += 1;
		if '+' not in s :
			print 'Case #'+str(x)+':',str(ans);
			return;
		for i in xrange(len(s)-1):
			if s[i] == '-' :
				s[i] = '+'
			else:
				s[i] = '-'
			if s[i] == s[i+1] :
				break;


t = int(raw_input())
for x in xrange(1,t+1):
	s = raw_input();
	solve(list(s))