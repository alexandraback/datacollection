# -*- coding:utf-8 -*-

f = open("input.txt","r")
lines  = int(f.readline())
i = 1

def vowels(a):
	if a == 'a':
		return True
	if a == 'e':
		return True
	if a == 'i':
		return True
	if a == 'o':
		return True
	if a == 'u':
		return True
	return False


while i<=lines:
	#Problem Start
	l = f.readline()
	s = l.split()
	L = s[0]
	n = int(s[1])
	
	st = -1
	ed = -1
	j = 0
	D = []
	length = len(L)
	while j<length:
		if vowels(L[j]):
			if st == -1:
				j=j+1
				continue
			else:
				ed = j-1
				D.append((st,ed))
				st = -1
				ed = -1


		else:
			if st == -1:
				st = j
		
		j=j+1
	if st != -1:
		ed = length-1
		D.append((st,ed))

	R = []
	for d in D:
		if (d[1]-d[0]+1) < n:
			R.append(d)
	for r in R:
		D.remove(r)

	y = 0

	if len(D) == 0:
		print "Case #%d: %d" % (i, y)
		i=i+1
		continue
#	print D


	j = 0
	a = 0
	while j<length:
		a = 0
		for d in D:
			if j > d[1]:
				continue
			if (j >= d[0]) and (j <= d[1]):
				if (d[1]-j+1)>=n:
					a = length - (j+n-1)
					#print "a", a, d[0], j
					break
				else:
					continue
			else:
				a = length - (d[0]+n-1)
			#	print "b", a, d[0]
				break
		
		y=y+a
		j=j+1


	#End
	print "Case #%d: %d" % (i, y)
	i=i+1

f.close
