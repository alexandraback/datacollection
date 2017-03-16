# coding: shift-jis

D = {}

import itertools
def Iter(Len):
	for i in range(2, Len):
		for c in itertools.combinations(range(Len),i):
			yield c

def calc(target, ex, a):
	for i in range(len(a)):
		if i in ex: continue
		if D[a[i]].has_key(target):
			return D[a[i]][target]
		if a[i] == target:
			D[a[i]][target] = [i]
			return [i]
		elif a[i] < target:
			#target -= a[i]
			#ex = ex + (i,)
			ret = calc(target-a[i], ex + (i,), a)
			if ret:
				D[a[i]][target] = ret + [i]
				return ret + [i]
	for i in range(len(a)):
		if i in ex: continue
		D[a[i]][target] = []
	return []
			
def solve(a):
	S = sum(a)
	for ex in Iter(len(a)):
		target = 0
		for i in ex:
			target += a[i]
		if target*2 > S: break
		ret = calc(target, ex, a)
		if ret != []:
			return [map(lambda x: a[x], ex), map(lambda x: a[x], ret)]
	return []

if __name__=='__main__':
	import sys
	f = file(sys.argv[1])
	caseCnt = int(f.readline())
	for case in range(1, caseCnt+1):
		a = map(int, f.readline().split())
		a = a[1:]
		a.sort()
		
		D = {}
		for ai in a:
			D[ai] = {}
		
		answer = solve(a)
		
		if answer == []:
			print "Case #%d: Impossible"%case
			continue
		print "Case #%d:"%case
		
		res = '%d'%answer[0][0]
		for r in answer[0][1:]:
			res += ' %d'%r
		print res
		
		res = '%d'%answer[1][0]
		for r in answer[1][1:]:
			res += ' %d'%r
		print res
	