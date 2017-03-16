import sys
fname = "C-small-attempt0.in"
fname = "C-large.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
# fo = sys.stdout
big = 5
s = ".*c"
def scan():
	for i in range(min(r,c)):
		t = i*(i+1)/2
		if m == t:
			a = []
			for k in range(i):
				a.append( s[1] * (i-k) + s[0] * (c-(i-k)) )
			for k in range(r-i):
				a.append(s[0] * c)
			a[r-1] = a[r-1][:-1] + s[2]
			for l in a:
				print >>fo,l
			return True
	for i in range(1,r+1):
		for j in range(1,c+1):
			for u in range(i):
				for v in range(j):
					if u * v != 0 or u+v == 0:
						t = (i+1)*(j+1) - u*v
						# print t
						if i == r:
							t -= j-v+1
						if j == c:
							t -= i-u+1
						if i ==r and j ==c and u+v ==0:
							t+=1
						if m == r*c-t:
							# print i,j,u,v,t,r*c-t
							a = []
							for k in range(min(i+1-u,r)):
								out = s[0] * (j+1) + s[1] * (c-j-1)
								out = out[:c]
								if k == 0:
									a.append (s[2]+ out[1:])
								else:
									a.append (out)
							for k in range(u):
								out = s[0] * (j+1-v) + s[1] * (c-j-1+v)
								out = out[:c]
								a.append(out)
							for k in range(r-i-1):
								a.append(s[1] * (c))
							mines = 0
							for k in range(r):
								print >>fo, a[k]
								assert (len (a[k])) == c
								for mine in a[k]:
									if mine == '*':
										mines += 1
							# print mines,m
							assert mines == m

							return True

	return False

for test in range(int(fi.readline())):
	r,c,m = [int(x) for x in fi.readline().strip().split()]
	print  >>fo,"Case #%d:"%(test+1)
	# print  >>fo,r,c,m
	solved = False
	if m == r*c -1:
		print >>fo, "c"+s[1]*(c-1)
		for i in range(1,r):
			print >>fo, s[1]*c
		solved = True
	else:
		solved = scan()
	if not solved:
		print >>fo, "Impossible"
