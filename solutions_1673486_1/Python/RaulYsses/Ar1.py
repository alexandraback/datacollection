import sys

T= int(sys.stdin.readline())
for i in range(1, T+1):
	line= sys.stdin.readline()
	AB= line.split(' ')
	A= int(AB[0])
	B= int(AB[1])
	P= sys.stdin.readline().split(' ')
	min= B+2
	p= 1
	for j in range(A):
		p*= float(P[j]) 
		keys= (A-j+B-j-1) + (1-p)*(B+1)
		if keys < min:
			min= keys
	sys.stdout.write("Case #" + str(i) + ": " + str(min) + "\n")
			
				
	