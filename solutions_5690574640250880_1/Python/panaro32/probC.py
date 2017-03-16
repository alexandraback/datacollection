#!/usr/bin/env python

from sys import stdin

def parse():
	l = map(int,stdin.readline().split())
	return (l[0],l[1],l[2])

def solve(r,c,m):
	f = []
	if r==1:
		f.append(['*' for k in range(m)] + ['.' for k in range(c-m-1)] + ['c'])
	elif c==1:
		for k in range(m):
			f.append(['*'])
		for k in range(r-m-1):
			f.append(['.'])
		f.append(['c'])
	elif r==2:
		if r*c-m==1:
			f.append(['*' for k in range(c)])
			f.append(['*' for k in range(c-1)] + ['c'])
		elif m%2==1 or r*c-m==2:
			return []
		else:
			f.append(['*' for k in range(m/2)] + ['.' for k in range(c-m/2)])
			f.append(['*' for k in range(m/2)] + ['.' for k in range(c-m/2-1)] + ['c'])
	elif c==2:
		if r*c-m==1:
			for k in range(r-1):
				f.append(['*','*'])
			f.append(['*','c'])
		elif m%2==1 or r*c-m==2:
			return []
		else:
			for k in range(m/2):
				f.append(['*','*'])
			for k in range(r-m/2-1):
				f.append(['.','.'])
			f.append(['.','c'])
	else:
		i = r
		while i>3 and m>=c:
			f.append(['*' for k in range(c)])
			i,m = i-1,m-c
		if i>3:
			if c-m>1:
				f.append(['*' for k in range(m)] + ['.' for k in range(c-m)])
				i -= 1
			else:
				f.append(['*' for k in range(c-2)] + ['.','.'])
				f.append(['*'] + ['.' for k in range(c-1)])
				i -= 2
			for j in range(i-1):
				f.append(['.' for k in range(c)])
			f.append(['.' for k in range(c-1)] + ['c'])
		else:
			b = c-m/3
			if m%3==0:
				if b<2:
					return []
				else:
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b-1)] + ['c'])
			elif m%3==1:
				if b<3:
					return []
				else:
					f.append(['*' for k in range(c-b+1)] + ['.' for k in range(b-1)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b-1)] + ['c'])
			else:
				if b==3:
					return []
				if b==1:
					f.append(['*' for k in range(c-b+1)] + ['.' for k in range(b-1)])
					f.append(['*' for k in range(c-b+1)] + ['.' for k in range(b-1)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b-1)] + ['c'])
				else:
					f.append(['*' for k in range(c-b+2)] + ['.' for k in range(b-2)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b)])
					f.append(['*' for k in range(c-b)] + ['.' for k in range(b-1)] + ['c'])
	return f

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(r,c,m) = parse()
		f = solve(r,c,m)
		print "Case #{0}:".format(i+1)
		if f==[]:
			print "Impossible"
		else:
			for k in f:
				print "{0}".format(''.join(k))
