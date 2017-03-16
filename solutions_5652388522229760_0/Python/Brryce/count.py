import sys

N =int(sys.stdin.readline().strip())
for qw in range(1,N+1):
	number = int(sys.stdin.readline().strip())
	if number == 0:
		print("Case #%d: INSOMNIA"%qw)
	else:
#	for number in range(1,1000000):
		ss = set()
		count = 1
		while len(ss)<10:
			tmp = number*count
			while(tmp>0):
				ss.add(tmp%10)
				tmp = tmp//10
			count +=1
		print("Case #%d: %d"%(qw,number*(count-1)))	
		
	
