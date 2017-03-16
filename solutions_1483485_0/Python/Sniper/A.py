import sys

pair = {'a':'y','b':'h','c':'e','d':'s','e':'o','f':'c','g':'v','h':'x','i':'d','j':'u','k':'i','l':'g','m':'l','n':'b','o':'k','p':'r','q':'z','r':'t','s':'n','t':'w','u':'j','v':'p','w':'f','x':'m','y':'a','z':'q'}

def learn(froms,tos):
	pair = {}
	for i in range(len(froms)):
		for j in range(len(froms[i])):
			pair[froms[i][j]] = tos[i][j]
	return pair

if __name__ == '__main__':
	fin = sys.stdin
	N = int(fin.readline())
	for i in xrange(N):
		line = fin.readline()[:-1]
		newline = []
		for j in range(len(line)):
			if line[j] in pair:
				newline.append(pair[line[j]])
			else:
				newline.append(line[j])
		print 'Case #%d: %s' % (i+1,''.join(newline))
