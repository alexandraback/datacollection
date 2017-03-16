import sys
import math

def numRings2(r, t):
				b = 2*r - 1
				a = 2
				c = -1*t
				root1 = (-1*b + math.sqrt(b*b-4*a*c)) / (2*a)
				root2 = (-1*b - math.sqrt(b*b-4*a*c)) / (2*a)
				#print root1, root2
				return math.floor(max(root1, root2))

def numRings(r, t):
				count = 0
				currR = r
				remainingT = t
				while remainingT > 0:
								remainingT -= (2*currR + 1)
								if (remainingT < 0):
												break
								count += 1
								currR += 2
								
				return count


lines = [x.strip() for x in open(sys.argv[1]).readlines()]
numCases = int(lines[0])
cases = [map(int, x.split(' ')) for x in lines[1:]]
for i in range(numCases)[:]:
				(r, t) = cases[i]
				num = numRings2(r, t)
				print "Case #%d: %d" % ((i+1), num)
				
