import sys
from sys import argv

def solve(N):
	if N == 0:
		print("INSOMNIA")
		return
	count = 0
	mul = 0
	array = [0] * 10
	num = 0
	while count < 10:
		mul = mul + 1
		num = N * mul
		s = str(num)
		for c in s:
			if array[int(c)]==0:
				array[int(c)]=1;
				count = count + 1
	print(num)

T = int(input())
for i in range(0, T):
	N = int(input())
	print("Case #",i+1,": ",sep="",end="")
	solve(N)
