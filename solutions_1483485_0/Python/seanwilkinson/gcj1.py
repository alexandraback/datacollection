f = open('A-small-attempt0.in')
N = int(f.readline())
cases = []
for i in range(0, N):
	cases.append(f.readline().strip())
f.close()

DecodeMap = {'a':'y', 
'b':'h',
'c':'e',
'd':'s',
'e':'o',
'f':'c',
'g':'v',
'h':'x',
'i':'d',
'j':'u',
'k':'i',
'l':'g',
'm':'l',
'n':'b',
'o':'k',
'p':'r',
'q':'z',
'r':'t',
's':'n',
't':'w',
'u':'j',
'v':'p',
'w':'f',
'x':'m',
'y':'a',
'z':'q',
' ':' ',
}

def GtoE(string):
	newstring = ''
	for letter in string:
		newstring += DecodeMap[letter]
	return newstring


g = open('A-small-attempt0.out', 'wt')
for j in range(0, N):
	g.write('Case #' + str(j+1) + ': ' + GtoE(cases[j]) + '\n')
g.close()

