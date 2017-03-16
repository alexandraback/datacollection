import math
case = input() 	
(N,J) = map(int,input().split())
print ("Case #1:")

base2 = 2**(N-1)+1
nums = list(map(lambda x: (x ** (N-1)) + 1, range(2,11)))
#print(nums)

found = 0
while found < J:
	testing = 0
	notprime = True
	divisors = []
	while notprime and (testing < (10 - 1)):
		divisor = 2
		while divisor < math.sqrt(nums[testing]) and ((nums[testing] % divisor) != 0) and divisor < 22000:
			divisor += 1
		if (nums[testing] % divisor) != 0:
			notprime = False
		else:
			divisors.append(divisor)
			testing += 1
	if notprime:
		print("{:b}".format(nums[0])," ".join(map(str,divisors)));
		#print(nums)
		found += 1
	base2 += 2
	base2list = list(map(int,list("{:b}".format(base2))))
	base2list.reverse()
	nums=[]
	for base in range(2,11):
		n = 0
		for i in range(N):
			n += base**i * base2list[i]
		nums.append(n)
	#nums = list(map(lambda x, y: x + y, nums, range(2,11)))
		
	
