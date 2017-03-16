# Brute force solution, upper bound on steps ~ 100

"""
Precomputation part... runs in < 1 min but i precompute for safety	
"""
"""
def GetDigits(n):
	ret = 0
	while (n>0):
		d = n%10
		ret=ret|(2**d)
		n=n/10
	return ret

f=open('A_precompute', 'w+')
for q in xrange(1000005):
	if q == 0:
		f.write('INSOMNIA\n')
		continue
	w = q
	d = 0
	while True:
		d = d | (GetDigits(w))
		if d == 1023: 
			f.write(str(w) + "\n")
			break
		w += q

f.close()
"""

with open('A_precompute') as f:
	content = f.readlines()
content = [line[:-1] for line in content]

T = int(raw_input())
for t in xrange(T):
	x = int(raw_input())
	print "Case #" + str(t+1) + ": " + content[x]