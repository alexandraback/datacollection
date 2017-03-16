C = [[], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1], [1, 5, 10, 10, 5, 1], [1, 6, 15, 20, 15, 6, 1], [1, 7, 21, 35, 35, 21, 7, 1], [1, 8, 28, 56, 70, 56, 28, 8, 1], [1, 9, 36, 84, 126, 126, 84, 36, 9, 1]]
import math
sqrt = math.sqrt
def search(n):
	i = 1
	while(i*(i+1)/2 <= n):i+=2
	return i-2

t = int(raw_input()) 
for cases in range(1,t+1):
	n,x,y = map(int,raw_input().split())
	c = search(n)
	if x < 0: x = -x
	print "Case #"+str(cases)+":",
	if x+y > c+1 :
		print "0.0"
		continue
	if x+y <= c-1:
		print "1.0"
		continue
	r = n - c*(c+1)/2
	if r == 0: 
		print "0.0"
		continue
	y+=1
	#print r,c
	ans = 0.000 
	MIN = max(0,r - c-1)
	
	den = 0 
	for i in range(MIN,(min(r,c+1)+1)):
		den += C[r][i]
	
	#print MIN,den
	
	for i in range(max(MIN,y),min(r+1,c+2)):
		ans += C[r][i]
	print (1.0*ans)/den