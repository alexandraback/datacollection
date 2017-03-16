lower = 1
upperpower = 14

squarepalindromes = []

from math import sqrt

def ispalindrome(n):
	s = str(n)
	return s == s[::-1]
	
def case():
	a,b = map(int,input().split())
	
	return len( list( filter(lambda n: a <= n and n <= b, squarepalindromes) ) )
	
def preprocess():
	for i in range(lower,10**(upperpower//2)+1):
		if ispalindrome(i) and ispalindrome(i*i):
			squarepalindromes.append(i*i)

			
preprocess()
for t in range(1,int(input())+1):
	print ( "Case #%d: %d" % (t,case()) )
