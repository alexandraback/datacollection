#coding:utf8
import sys
result = {
	"fi": "C-small-attempt1.in",
	"fo": "c.out",
	"ct": ""
}
def myprint(*x):
	s = ''.join(map(str,x))
	sys.stdout.write(s)
	result['ct'] += s


def dis(r,c,m):
	ret = []
	t = r*c-m
	if t / c < 2:
		if t % 2 == 0:
			if t/2>=2:
				ret = [t/2,t/2]
			else:
				ret = []
		else:
			if t<3 or r<3:
				ret = []
			else:
				d = (t-3)/2 
				if d<3:
					ret = []
				else:
					ret = [d,d,3]
		pass
	elif t / c == 2:
		if t%c > 1:
			ret = [c,c,t%c]
		elif t%c == 0:
			ret = [c,c]
		else:
			if c<=3:
				return []
			else:
				ret = [c-1,c-1,t%c+2]
		pass
	else:
		while t>=c:
			ret.append(c)
			t-=c
		if t == 1:
			if c == 2:
				return []
			ret[-1] = c-1
			t+=1
		if t:
			ret.append(t)
	return ret
def cal(r,c,m):
	if m == r*c-1:
		b = [['*']*c for _ in range(r)]
		b[0][0] = 'c'
		return '\n'.join(map(lambda x:''.join(x),b))

	if c == 1:
		return '\n'.join(['*']*(m) + ['.']*(r*c-m-1) + ['c'])

	if r == 1:
		return '*'*m + '.'*(r*c-m-1) + 'c'

	if r*c-m < 4:
		return "Impossible"

	x = dis(r,c,m)
	if not x:
		return "Impossible"

	b = [['*']*c for _ in range(r)]
	print r,c,m,x
	for i in range(len(x)):
		b[i][:x[i]] = ['.'] * x[i]
	b[0][0] = 'c'
	print '\n'.join(map(lambda x:''.join(x),b))
	return '\n'.join(map(lambda x:''.join(x),b))

def main():
	with open(result['fi'], 'r') as f:
		lines = [line for line in f]
	lines.reverse()
	#print lines
	n = int(lines.pop())
	for i in range(1,n+1):
		r,c,m = map(int,lines.pop().split())
		print r,c,m
		myprint("Case #%d:\n%s\n" % (i, cal(r,c,m)))

	with open(result['fo'], 'w') as f:
		f.write(result['ct'])

if __name__ == '__main__':
	main()