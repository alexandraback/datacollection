import sys

fin = open(sys.argv[1], "r")
fout = open("B.out", "w")

def reverse_numeric(x, y):
    return y - x

def ceildiv(a, b):
    return -(-a // b)        

T = int(fin.readline())
for i in xrange(T):
	length = int(fin.readline())
	a = map(int, fin.readline().split())
	a = sorted(a, cmp=reverse_numeric)

	solmin = a[0]
	sol = solmin
	num = 0
	alist = [a]
	nlist = [num]
	while len(alist)>0:
		while (a[0] > 2):
#			max = a[0]
#			print '%2d' % sol, a
#			a.pop(0)
#			print a
			max = a[0]
			if max < 9:
				max = a[0]
				print '%2d' % sol, a
				a.pop(0)
				if ceildiv (max,2) >0:
					a.append( ceildiv(max,2) )
					a.append( max- ceildiv(max,2) )
				a = sorted(a, cmp=reverse_numeric)
				num += 1
				sol = a[0] + num
				if sol < solmin:
					solmin = sol
			else:
				a1 = a[:]
				num1 = num
				for m in range (2):
					max = a1[0]
					print '%2d' % sol, a1, a
					a1.pop(0)
					if ceildiv (max,2) >0:
						a1.append( ceildiv(max,2) )
						a1.append( max- ceildiv(max,2) )
					a1 = sorted(a1, cmp=reverse_numeric)
					num1 += 1
					sol = a1[0] + num1
					if sol < solmin:
						solmin = sol
				for m in range (1):
					max = a[0]
					print '%2d' % sol, a
					a.pop(0)
					if ceildiv (max,3) >0:
						a.append( ceildiv(max,3) )
						a.append( ceildiv(max- ceildiv(max,3),2 ))
						a.append( max - ceildiv(max- ceildiv(max,3),2 )-ceildiv (max,3))
					a = sorted(a, cmp=reverse_numeric)
					num += 2
					sol = a[0] + num
					if sol < solmin:
						solmin = sol	
				alist.append(a1)			
				nlist.append(num1)
		if a[0]<=2:
			alist.pop(0)
			nlist.pop(0)
			if len(alist)>0:	
				a = alist[0]
				num = nlist[0]
			
					
					

		print '%2d' % sol, a
		print solmin		

	fout.write("Case #" + str(i+1) + ": " + str(solmin) + "\n")