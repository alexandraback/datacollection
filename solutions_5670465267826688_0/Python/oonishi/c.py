#coding: cp932
# 2015 Qualification Problem C
input = iter('''
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
'''.splitlines()[1:])
import sys
output = sys.stdout

input  = open(r'C-small-attempt0.in')
output = open(r'C-small-attempt0.out', 'w')

#input  = open(r'C-small-practice-2.in')
#output = open(r'C-large-practice.out', 'w')

M = {
'1': {'1':('1',0), 'i':('i',0), 'j':('j',0), 'k':('k',0)},
'i': {'1':('i',0), 'i':('1',1), 'j':('k',0), 'k':('j',1)},
'j': {'1':('j',0), 'i':('k',1), 'j':('1',1), 'k':('i',0)},
'k': {'1':('k',0), 'i':('j',0), 'j':('i',1), 'k':('1',1)},
}

def cnv(c, d, f):
	c2,f2 = M[c][d]
	return c2,(f2+f)%2
	
	

def setup(S):
	global I,K
	L = len(S)
	I = [('1',0)]
	
	ci = '1'
	fi = 0
	for i in range(L-2):
		ci,fi = cnv(ci,S[i],fi)
		I += [(ci,fi)]
		
	K = []
	ck = '1'
	fk = 0
	for i in range(L-1,1,-1):
		ck,fk = cnv(S[i],ck,fk)
		K += [(ck,fk)]
	K.reverse()
	K = [None,None,] + K
	#print(I)
	
def cnvs(s):
	c = '1'
	f = 0
	for d in s:
		c,f = cnv(c,d,f)
	return c,f
	

def solve(S,X):
	S = S*X
	setup(S)
	L = len(S)
	for i in range(1,L-1):
		ci,fi = I[i]
		if ci != 'i' or fi != 0: continue
		cj,fj = '1',0
		for k in range(i+1,L):
			ck,fk = K[k]
			
			
			cj,fj = cnv(cj,S[k-1],fj)
			#print(i,k,k-1,S[i:k],cj,fj)
			if ck != 'k' or fk != 0: continue
			if cj == 'j' and fj == 0:
				return 'YES'
	#raise
	return 'NO'

	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	L,X, = map(int, next(input).split())
	S = next(input).strip()
	answer = solve(S,X)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
print(time.time()-st)