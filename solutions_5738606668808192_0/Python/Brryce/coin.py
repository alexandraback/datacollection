import sys
import math

N = int(sys.stdin.readline().strip())
for qw in range(1,N+1):
	print("Case #%d:"%qw)
	tmp = sys.stdin.readline().strip().split()
	n = int(tmp[0])
	j = int(tmp[1])
	count = 0
	for i in range(2**(n-2)):
		if count == j:
			break
		#get a sample of list
		ll=[1]
		ii = i
		for k in range(n-2):
			ll.append(ii%2)
			ii = ii//2
		ll.append(1)
		#  2-10
		result = []
		for base in range(2,11):
			# get each based number
			number = 0
			flag = False
			for wei in range(n):
				number +=ll[-wei-1]*(base**wei)
			# get the smallest yinzi
			for ite in range(2,int(math.sqrt(number))+1):
				if number % ite ==0:
					flag =True
					break
			if flag:
				result.append(ite)
			else:
				result = []
				break
		if len(result)==9:
			count +=1
			print("%s %s"%("".join(str(num) for num in ll)," ".join(str(num) for num in result)))

