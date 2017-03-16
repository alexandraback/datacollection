'''
Zero
siX
eiGht
tWo
foUr
One
Three
Five
Seven
Nine
'''

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

unique = [('Z',0,'ZERO'),('X',6,'SIX'), ('G',8,'EIGHT'),
	('W', 2, 'TWO'), ('U', 4, 'FOUR'), ('O', 1, 'ONE'), ('T', 3, "THREE"),
	('F', 5, "FIVE"), ('S', 7, "SEVEN"), ('N', 9, "NINE")]

	

def solve(s):
	s = list(s)
	result = []
	for c,n,n_str in unique:
		while c in s:
			for d in n_str:
				s.remove(d)
			result.append(n)
	result.sort()
	return ''.join(map(str,result))
	

n_cases = input()
for i in range(1,n_cases+1):
	s = raw_input()
	print 'Case #%d:' % i,
	print solve(s)