import sys
D = {'y':'a','n':'b','f':'c','i':'d','c':'e','w':'f','l':'g','b':'h','k':'i','u':'j','o':'k',
	 'm':'l','x':'m','s':'n','e':'o','v':'p','z':'q','p':'r','d':'s','r':'t','j':'u','g':'v',
	 't':'w','h':'x','a':'y','q':'z',' ':' '}
def translate(G):
	S = ''
	for c in G:
		S += D[c]
	return S

if __name__=='__main__':
	f = open(sys.argv[1], 'r')
	T = int(f.readline()[:-1])
	for case_no in range(1, T + 1):
		G = f.readline()[:-1]
		S = translate(G)
		print "Case #%s: %s" % (case_no, S)
	
