def see(n):
	global seen
	seen[n%10] = 1
	if n >= 10:
		see(n/10)

n = input()
for i in range(n):
	x = input()
	if x == 0:
		print "Case #%d:" % (i+1) + " INSOMNIA"
		continue
	seen = [0]*10
	j = 1
	while sum(seen) != 10:
		see(x*j)
		j += 1
	print "Case #%d: %d" % (i+1,(j-1)*x)
	#print "\t" + " ".join(map(str,[k*x for k in range(1,j)]))