def flip(s, a, b):
	s = s[:a] + s[a:b].replace('+','a').replace('-','+').replace('a','-') + s[b:]
	return s

def solve(s):
	n = 0
	while s.count('-') > 0:
		#print(s)
		if s[0] == '+':
			n += 1
			s = flip(s,0,s.find('-'))
		n += 1
		s = flip(s,0,s.rfind('-')+1)
	return n

if __name__ == '__main__':
	tc = int(input())
	for t in range(1, tc+1):
		s = input()
		print('Case #%i: %i' % (t, solve(s)))
	
