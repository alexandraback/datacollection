from math import sqrt

def palindrome(i):
	if str(i)==str(i)[::-1]:
		return 1
	return 0

T = eval(input())
for k in range(T):
	AB = input().split(" ")
	A = eval(AB[0])
	B = eval(AB[1])
	a = 1 + int(sqrt(A-1));
	b = int(sqrt(B));
	contador = 0
	for i in range(a,b+2):
		if palindrome(i) == 1:
			break;
	if i<10:
		part = i;
	else:
		part = int(str(i)[:-int(len(str(i))/2)])
	while i<=b:
		lenght = len(str(i))
		max = 10**lenght-1
		#part = int(str(i)[:-int(lenght/2)])
		if lenght%2 == 0:
			while max != i <= b:
				if palindrome(i*i) == 1:
					contador += 1
				part += 1
				i=str(part)+str(part)[::-1]
				i=int(i)
			else:
				part += 1
				i += 2
		else:
			while max != i <= b:
				if palindrome(i*i) == 1:
					contador += 1
				part += 1
				i=str(part)+str(part)[:-1][::-1]
				i=int(i)
			else:
				part += 1
				i += 2
				part = int(part/10)
	print("Case #"+str(k+1)+":",contador);
