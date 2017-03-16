

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
	
	prod = 1
	for j in range(0,A):
		prod = prod*p[j]
	
	for k in range(0,A):
		
		
		# print k,prod,prod*(2*k+B-A+1)+(1-prod)*(2*k+2*B-A+2)
		r = min(r,prod*(2*k+B-A+1)+(1-prod)*(2*k+2*B-A+2))
		prod = prod / p[A-k-1]
	
	print "Case #"+str(i+1)+": %0.6f"%r



def stringArrayToVector(arr):
	res = []
	for s in arr:
		res += [int(s)]
	return res