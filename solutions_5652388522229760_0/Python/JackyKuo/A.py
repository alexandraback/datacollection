import sys
def addDigits(num, s):
	while num > 0:
		tmp = num%10
		if tmp not in s:
			s.add(tmp)
		num //= 10

def main():
	num = int(input())
	f = open('data.txt', 'w')
	for i in range(1, num+1):
		N = int(input())
		s = set()
		numSet = set()
		j = 1
		while len(s) < 10:
			#print(s)
			addDigits(N*j, s)
			if N*j in numSet:
				break
			numSet.add(N*j)
			j += 1
		if len(s) is 10:
			print("Case #%d: %d" % (i, N*(j-1)), file= f)
		else:
			print("Case #%d: INSOMNIA" % i, file = f)
main()
