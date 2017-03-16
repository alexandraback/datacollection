import gmpy

T = int(raw_input())

for i in range(T):
	line = raw_input().split(' ')
	r = int(line[0])
	t = int(line[1])

	n = (gmpy.sqrt(4*r*r-4*r+8*t+1) -2*r-3)/4
	#print (4*r*r-4*r+8*t+1), gmpy.sqrt(4*r*r-4*r+8*t+1)
	#print r*(4-4/r+8*t/r/r+1/r/r), r*(4-4/r+8*t/r/r+1/r/r)**.5

	print 'Case #'+str(i+1)+':', int(n)+1

'''
	n = 1
	usada = 2*r+1
	while usada < t:
		usada += 2*(r+2*n)+1
		n += 1
	print 'Case #'+str(i+1)+':', (n-1)
'''

