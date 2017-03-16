from bisect import *

def palin(a):
	return str(a) == str(a)[::-1]

arr = []
for i in xrange(1, 10**7):
	n = str(i) + str(i)[::-1]
	n = int(n)**2
	if palin(n):
		arr.append(n)
	n = str(i) + (str(i)[::-1])[1:]
	n = int(n)**2
	if palin(n):
		arr.append(n)
	if i % 100000 == 0:
		print i, len(arr)
arr.sort()
print arr

Z = int(raw_input())

for z in xrange(Z):
	print "Case #" + str(z+1) + ":",
	a, b = map(int, raw_input().split())
	print bisect_right(arr, b) - bisect_left(arr, a)
