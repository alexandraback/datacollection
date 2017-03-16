#!/usr/bin/python
import sys
import math

isVowel=[0]*200
isVowel[ord('a')]=1
isVowel[ord('e')]=1
isVowel[ord('i')]=1
isVowel[ord('o')]=1
isVowel[ord('u')]=1


def init(word, n):
	l = len(word)
	A = [0]*l
	for i in range(l):
		v = 0
		for j in range(i, min(i+n, l)):
			v += 1-isVowel[ord(word[j])]
		A[i] = 1 if v>=n else 0
	return A

inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
l = 1
for t in range(T):
	arr = inp[l].split(" ")
	word = arr[0]
	n = int(arr[1])
	l += 1

	A0 = init(word,n)
	F1 = init(word,n)
	F2 = [0]*len(word)
#	print word,n,A0

	le = len(word)
	total = 0
	for k in range(n, le+1):
		tmp = F2
		F2 = F1
		F1 = tmp
		for i in range(le):
			if i+k<=le:
#				print i,k,le
				F2[i] = (F1[i+1] if i+1<le else 0) or A0[i]
			else:
				F2[i] = 0
		total += sum(F2)
#		print k, F2

	print "Case #%d: %d" % (t+1, total)

