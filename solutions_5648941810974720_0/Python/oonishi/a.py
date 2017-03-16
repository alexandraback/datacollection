#coding: utf8


s = '''\
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('A-small-attempt4.in')
out   = open('A-small-attempt4.out', 'w')

#input = open('C-large.in')
#out   = open('C-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy
L = {"ZERO":'0', "ONE":'1', "TWO":'2', "THREE":'3', "FOUR":'4', "FIVE":'5', "SIX":'6', "SEVEN":'7', "EIGHT":'8', "NINE":'9'}
L = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
#Rev = {v:k for k,v in L.items()}

#s = set()
#for l in L:
#	for c in l:
#		s.add(c)
#print(s)
C = ['H', 'W', 'U', 'S', 'E', 'R', 'V', 'Z', 'O', 'T', 'F', 'I', 'G', 'N', 'X']
#EOTEOEWNNEVOOONSTNEW
#ONEONEONEONETWO
#
#EVSTW
#
#EOTEOEWNNEVOOONSTNEW

def test(d, w):
	d2 = deepcopy(d)
	
	for c in w:
		if d2[c] == 0:
			return False
		d2[c] -= 1
	return True
	
	
def search(d, n):
	d = deepcopy(d)
	if n == 10:
		for v in d.values():
			if v != 0:
				return 'ERROR'
		return ''
	w = L[n]
	
	res = search(d, n+1)
	if res != 'ERROR':
		return res
	res = ''
	while test(d, w):
		res += str(n)
		for c in w:
			d[c] -= 1
		ans = search(d, n+1)
		if ans != 'ERROR':
			return res + ans
	
	ans = search(d, n+1)
	if ans != 'ERROR':
		return res + ans
	return 'ERROR'
		
	

def solve(S):
	d = defaultdict(int)
	for c in S:
		d[c] += 1
	res = search(d, 0)
	if res == 'ERROR':
		raise
	return res
			

def solve_(S):
	D = {c:0 for c in C}
	D['@'] = 0
	res = ''
	for c in (S + '@'):
		D[c] += 1
		for w in L:
			d = deepcopy(D)
			for k in w:
				if d[k] == 0:
					break
				d[k] -= 1
			else:
				res += L[w]
				for k in w:
					D[k] -= 1
					if D[k] < 0:
						print(c)
						print(d)
						print(D)
						print(w)
						raise
	
	print(D)
	res = ''.join(sorted(res))
	
	rev = ''
	for c in res:
		rev += Rev[c]
		
	if sorted(rev) != sorted(S):
		print(S)
		print(rev)
		raise
	
	return res
	

CaseCnt = int(next(input))
for case in range(CaseCnt):
	S = next(input).strip()
	#N, = map(int, next(input).split())
	#*F, = map(int, next(input).split())
	print(S)
	ans = solve(S)
	
	print('Case #%d:'%(case+1), ans, file=out)
