import sys
import numpy
sys.setrecursionlimit(10000)


b = [
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
]

c = [[0]*26 for i in range(10)]
for i in range(10):
	for x in b[i]:
		c[i][ord(x)-ord('A')] += 1

allletters = sorted(''.join(list(set(list(sorted(''.join(b)))))))
tenletters = allletters[:10]


d = [[0]*10 for i in range(10)]
for i in range(10):
	for j in range(10):
		d[j][i] = b[i].count(tenletters[j])





def foo2(s):
	a = [0]*10
	for i in range(10):
		a[i] = s.count(tenletters[i])
	res = [int(round(x)) for x in list(numpy.linalg.solve(d, a))]
	res2 = ''.join([str(i)*res[i] for i in range(10)])
	return res2




def foo(ifile):
	s = ifile.readline().strip()
	return foo2(s)
 


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

