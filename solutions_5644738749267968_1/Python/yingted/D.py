#!/usr/bin/pypy
from bisect import bisect_left
def B(b,a):
	i=bisect_left(b,a)
	if i==len(b):
		return 0
	return i
def deceitful(a,b):
	chosen=a[0]
	del a[0]
	if chosen<b[0]: # loser
		return chosen,b[-1]
	return chosen,1.
def honest(a,b):
	told=a[0]
	del a[0]
	return told,told
def main():
	for T in xrange(1,1+int(raw_input())):
		print"Case #%d:"%T,
		N=int(raw_input())
		a=map(float,raw_input().split())
		b=map(float,raw_input().split())
		a.sort()
		b.sort()
		scores=[]
		for A in deceitful,honest:
			a2=a[:]
			b2=b[:]
			n2=N
			score=0
			while n2:
				assert len(a2)==len(b2)==n2
				chosen,told=A(a2,b2)
				j=B(b2,told)
				assert(chosen>b2[j])==(told>b2[j])
				score+=told>b2[j]
				del b2[j]
				n2-=1
			scores.append(score)
		print scores[0],scores[1]
if __name__=="__main__":
	main()
