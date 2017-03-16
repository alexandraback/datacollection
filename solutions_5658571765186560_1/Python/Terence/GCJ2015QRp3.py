import sys

def winner(x,r,c):
	res = 'RICHARD'
	if r*c%x:
		return res
	elif x <= 2:
		res = 'GABRIEL'
	elif x == 3:
		if min(r,c) > 1:
			res = 'GABRIEL'
	elif x == 4:
		if min(r,c) >= 3 and max(r,c) >= 4:
			res = 'GABRIEL'
	elif x == 5:
		if min(r,c) >= 3 and max(r,c) >= 5:
			res = 'GABRIEL'
	elif x == 6:
		if min(r,c) >= 4 and max(r,c) >= 6:
			res = 'GABRIEL'
	return res

#fi = sys.stdin
#fo = sys.stdout
#fi = open('D-small-attempt0.in','r')
#fo = open('D-small-attempt0.out','w')
fi = open('D-large.in','r')
fo = open('D-large.out','w')

t = int(fi.readline())
for _ in range(t):
	x,r,c = map(int,fi.readline().split())
	fo.write('Case #%d: %s\n' % (_+1, winner(x,r,c)))
fi.close()
fo.close()
