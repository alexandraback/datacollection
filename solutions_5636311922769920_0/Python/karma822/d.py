import sys
import math
from sys import argv

def solve(K, C, S):
	if math.ceil(K/C) > S:
		print(" IMPOSSIBLE")
		return
	start = 0
	while start < K:
		print(" ",end="")
		value = 0
		for num in range(0, C):
			value = value * K + start%K
			start = start + 1
		print(value+1,end="")
	print("")
	
		

T = int(input())
for i in range (0, T):
	KCS = input()
	tokens = KCS.split();
	K = int(tokens[0])
	C = int(tokens[1])
	S = int(tokens[2])
	print("Case #",i+1,":",sep="",end="")
	solve(K, C, S)
