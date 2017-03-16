input = """20
2 5
0.600000 0.600000
1 20
1.000000
3 4
1.000000 0.900000 0.100000
3 10
0.992179 0.865636 0.036924
2 7
0.174718 0.840523
2 5
0.027402 0.562263
3 100
0.598943 0.993042 0.043296
3 42
0.999998 1.000000 0.999998
3 10
0.900735 0.074285 0.868412
3 4
0.999999 1.000000 0.512374
1 3
0.000007
2 3
0.999998 0.999998
1 4
0.999998
3 10
0.007150 0.954953 0.054917
2 60
0.151298 0.223386
3 5
0.570201 0.594848 0.152851
2 7
0.944748 0.021186
3 42
0.000003 0.000008 0.000004
3 17
0.142256 0.494866 0.281008
2 4
0.000007 0.000004"""

lines = input.split("\n")

#Nombre de lignes pour un input
t = 2

for i in range(0,len(lines)/t):
	
	# Input i
	inp = lines[1+t*i:t*(i+1)+1]
	
	# Coder ici
	
	r = 0
	
	
	l1 = inp[0].split(" ")
	l2 = inp[1].split(" ")
	
	A = int(l1[0])
	B = int (l1[1])
	p = [float(s) for s in l2]
	
	r = B+2
	# print A,B,p
	
	for k in range(0,A):
		
		prod = 1
		for j in range(0,A-k):
			prod = prod*p[j]
		
		# print k,prod,prod*(2*k+B-A+1)+(1-prod)*(2*k+2*B-A+2)
		r = min(r,prod*(2*k+B-A+1)+(1-prod)*(2*k+2*B-A+2))
	
	print "Case #"+str(i+1)+": %0.6f"%r



def stringArrayToVector(arr):
	res = []
	for s in arr:
		res += [int(s)]
	return res