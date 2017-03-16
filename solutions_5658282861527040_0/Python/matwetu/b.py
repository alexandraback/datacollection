#coding:utf8
import sys
result = {
	"fi": "B-small-attempt0 (1).in",
	"fo": "b.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s

def slow(a,b,k):
	r = 0
	for i in range(a):
		for j in range(b):
			t = i&j
			if t < k:
				r+=1
	return r

def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		A,B,K = map(int,lines.pop().split())


		myprint("Case #%d: " % i)
		myprint(slow(A,B,K))
		myprint('\n')
	with open(result['fo'], 'w') as f:
		f.write(result['ct'])


if __name__ == '__main__':
	main()
