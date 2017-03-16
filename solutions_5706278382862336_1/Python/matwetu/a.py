#coding:utf8
import sys
result = {
	"fi": "A-large.in",
	"fo": "a.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)

def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		p,q = map(int,lines.pop().split('/'))
		d = gcd(p,q)
		p,q = p/d, q/d
		myprint("Case #%d: " % i)
		if 2**40 % q != 0:
			myprint('impossible\n')
		else:
			cnt = 0
			while p<q:
				q = q/2
				cnt+=1
			myprint('%d\n' % cnt)
	with open(result['fo'], 'w') as f:
		f.write(result['ct'])

if __name__ == '__main__':
	main()