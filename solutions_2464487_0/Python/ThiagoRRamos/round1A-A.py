import math

def solve(r,t):
	total = 0
	cou = 0
	while total <= t:
		total+= 2*(r+2*cou)+1
		cou +=1
	return cou-1

print solve(1,9)
print solve(1,10)
print solve(3,40)

f = open("A-small-attempt0.in")
t = int(f.readline())
i=1
while i<=t:
	(r,t) = f.readline().split(" ")
	n = int(r)
	m = int(t)
	print "Case #"+str(i)+":",solve(n,m)
	i+=1