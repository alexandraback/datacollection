mapping = {
	'a':'y',
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
	'\n':'\n',
}


if __name__ == '__main__':
	import sys
	T = int(sys.stdin.readline())
	for i in xrange(T):
		G = sys.stdin.readline()
		array = map((lambda x: mapping[x]), G)
		sys.stdout.write( "Case #%d: %s" % (i + 1,''.join(array)) )


