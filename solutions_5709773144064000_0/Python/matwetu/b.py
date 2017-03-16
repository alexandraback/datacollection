#coding:utf8
import sys
result = {
	"fi": "B-small-attempt0.in",
	"fo": "b.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s


def cal(c,f,x):
	k = 0
	s = 0
	while((x-c)/(2+k*f) > x/(2+(k+1)*f)):
		s += c/(2+k*f)
		k += 1
	s += x/(2+k*f)
	return s

def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		c,f,x = map(float,lines.pop().split())
		print c,f,x
		myprint("Case #%d: %.10f\n" % (i, cal(c,f,x)))

	with open(result['fo'], 'w') as f:
		f.write(result['ct'])

if __name__ == '__main__':
	main()