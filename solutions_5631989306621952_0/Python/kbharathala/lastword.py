def last_word(s):
	f = s[0]
	for c in s[1:]:
		f = (f + c) if c < f[0] else (c+f)
	return f

f = open('A-small-attempt0.in.txt', 'r')
f2 = open('outputSmall.txt', 'w')
final = ''

for i in range(1, int(f.readline().strip())+1):
	s = f.readline().strip()
	final += 'Case #{}: {}\n'.format(i, last_word(s))

f2.write(final)

