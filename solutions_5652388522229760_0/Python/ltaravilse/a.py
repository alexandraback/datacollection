import sys
n = input()
for i in range(0,n):
	a = input()
	if a == 0:
		print "Case #"+str(i+1)+": INSOMNIA"
	else:
		array = [0,0,0,0,0,0,0,0,0,0]
		b = 0
		c = 0
		while b == 0:
			c += a
			d = c
			while d != 0:
				array[d%10] = 1
				d /= 10
			b = 1
			for j in range(0,10):
				if array[j] == 0:
					b = 0
		print "Case #"+str(i+1)+": "+str(c)