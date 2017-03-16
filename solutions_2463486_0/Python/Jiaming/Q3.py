
import math

def find(i,j):
	for i in xrange(i,j+1):
		si = str(i)
		if isp(si):
			yield i
			i += 1

def isp(s):
    if len(s) <= 1:
        return True
    if s[0] != s[-1]:
        return False
    return isp(s[1:-1])

def solve(filename):
    f = open(filename)
    out = open(filename + '.out.txt','w')
    n = int(f.readline())
    for i in xrange(n):
        a,b = map(int,f.readline().split())
        low,high = int(math.ceil(math.sqrt(a))), int(math.floor(math.sqrt(b)))
        count = 0
        for x in find(low,high):
            ix = int(x)
            if isp(str(ix**2)):
                count += 1
        out.write('Case #'+str(i+1)+ ': '+ str(count)+'\n')
    out.close()
    f.close()
