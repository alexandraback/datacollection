z = 'yhesocvxduiglbkrztnwjpfmaq'
cnt, n = 1, int(input())

def change(c):
	return z[ord(c) - ord('a')] if c != ' ' else ' '

while cnt <= n:
	print('Case #%d: %s' % (cnt, ''.join(map(change, input()))))
	cnt += 1
	