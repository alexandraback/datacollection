#!/usr/bin/python
from collections import deque
from decimal import *

'''
Ahmad Medhat Othman
AMedOs
me@amedhat.info
'''

def main():
	fin = open('C-small-attempt0.in', 'r')
	fout = open('C.out','w')
	T = long(fin.readline())
	
	for tc in range(1,T+1):
		words = map(int, fin.readline().split())
		N = words[0]
		S = words[1:]
		best = {}
		summ = {}
		for i in range(0,1<<N):
			done= False
			arr = []
			for j in range(N):
				if (i>>j & 1):
					arr.append(S[j])
			best[i] = arr
			ss = sum(arr)
			if ss != 0 and ss in summ:
				for s in summ[ss]:
					if solve(arr, s):
						fout.write("Case #" + str(tc) + ": " + "\n")
						fout.write(" ".join(map(str, s)) + "\n")
						fout.write(" ".join(map(str,arr)) + "\n")
						done = True
			elif ss != 0:
				if ss in summ:
					summ[ss].append(arr)
				else:
					summ[ss] = [arr]
			if done:
				break
def solve(a, b):
	res = list(set(a) & set(b))
	if len(res) <= 0:
		return True
	else:
		return False
if __name__ == '__main__':
	main()

