import sys
import math
import gmpy
import cProfile
from IO import getInput , printSolutions

def myXrange(start,stop):
   i = start
   while i < stop:
       yield i
       i += 1


def isSquare(apositiveint):
  if apositiveint==1:
	  return True
  x = apositiveint // 2
  seen = set([x])
  while x * x != apositiveint:
    x = (x + (apositiveint // x)) // 2
    if x in seen: return False
    seen.add(x)
  return True

def isSquareOfPalindrome(num):
	#~ if isSquare(num):
	if gmpy.is_square(num):
		return isPalindrome(int(math.sqrt(num)))
	return False

def calcLUT(start,stop):
	num=start
	lut = []
	while(num<=stop):
		if str(num) == str(num)[::-1] and str(num**2) == str(num**2)[::-1] :
			lut.append(num**2)
		num+=1
	return lut

def isPalindrome(num):
	return str(num) == str(num)[::-1]

def main():
	
		
	start = int(math.ceil( math.sqrt( 1 ) )) 
	#~ stop = int(math.floor( math.sqrt( 10**14 ) ))
	stop = int(math.floor( math.sqrt( 1000 ) ))
	
	print start
	print stop
		
	lut = calcLUT(start,stop)
	print lut
	
	
	cases = getInput(sys.argv[1])
	
	solutions=[]
	
	for case in cases:
		assert(start>=1)
		assert(stop<=1000)
		start = case[0]
		stop = case[1]
		nums = [ num for num in lut if start <= num and num <= stop ]
		solutions.append(len(nums)) 
		
	printSolutions(sys.argv[2],solutions)
	

if __name__ == "__main__":
    main()
