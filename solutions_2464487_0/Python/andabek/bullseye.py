import math
import decimal

def rings(r, t):

	aux = decimal.Decimal(4*r*r-4*r+8*t+1).sqrt()
	aux += decimal.Decimal(-2*r+1)
	aux /= 4
	#aux = math.floor(aux)
	return int(aux)
				



## Main
f = open('A-small-attempt0.in')
## Read the first line 
line = f.readline()
n = int(line)
line = f.readline()

decimal.getcontext().prec = 100
k=0
while k<n:
	l = line.split()
	r = int(l[0])
	t = int(l[1])
	print 'Case #'+ str(k+1) + ': ' + str(rings(r,t))
	line = f.readline()
	k=k+1
f.close()


