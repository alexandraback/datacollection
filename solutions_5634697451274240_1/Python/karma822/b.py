import sys
import math
from sys import argv

def solve(S):
	prev=S[0]
	count = 0
	for c in S[1:]:
		if c!=prev:
			count = count + 1
		prev = c
	if S[-1]=='-':
		count = count + 1
	print(count)

T = int(input())
for i in range(0, T):
	S = input()
	print("Case #",i+1,": ",sep="",end="")
	solve(S)
