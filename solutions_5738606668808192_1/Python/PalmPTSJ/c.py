import random
input()
N,J = [int(x) for x in input().split()]

found = 0
random.seed(555)
fermatTest = [2,3,4,5,6,7,8,9,10]
def isComposite(x) :
	for a in fermatTest :
		if pow(a,x-1,x) != 1 : return True
	return False
def findDiv(x) :
	for i in range(3,1000,2) :
		if x%i == 0 : return i
	return None

founded = set()

print("Case #1:")

while found < J :
	num = "1"
	for i in range(N-2) : 
		num += "01"[random.randint(0,1)]
	num += "1"
	if num in founded : continue
	ans = [1,1,1,1,1,1,1,1,1]
	for base in range(2,11) :
		x = int(num,base)
		if isComposite(x) :
			d = findDiv(x)
			if d == None : break
			ans[base-2] = str(d)
		else : break
	else :
		found += 1
		founded.add(num)
		print(num," ".join(ans))
	#break