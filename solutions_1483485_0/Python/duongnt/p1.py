# Speaking in Tongues

table = {' ':' ', 'y':'a', 'n':'b', 'f':'c', 'i':'d', 'c':'e', 'w':'f', 'l':'g', 'b':'h', 'k':'i', 'u':'j', 'o':'k', 'm':'l', 'x':'m', 's':'n', 'e':'o', 'v':'p',
		'z':'q', 'p':'r', 'd':'s', 'r':'t', 'j':'u', 'g':'v', 't':'w', 'h':'x', 'a':'y', 'q':'z'}
		
T = int(raw_input())
for i in range(T):
	line = raw_input()
	ans = ''.join(table[k] for k in line)
	print 'Case #%d: %s' %(i+1,ans),
	if i < T-1: print