#coding: cp932
# 2015 Qualification Problem C


import ctypes
dll = ctypes.cdll.c
dll.solve.argtypes = (ctypes.c_char_p, ctypes.c_int, ctypes.c_int)
dll.hello.argtypes = (ctypes.c_char_p, ctypes.c_int, ctypes.c_int)
#dll.hello('ijk'.encode(), 32, 88)
#exit()
#s = b'kjkjkj'
#dll.hello(s, len(s), 1);
#s = b'kjk'
#dll.hello(s, len(s), 1);
#s = b'jkjkjkj'
#dll.hello(s, len(s), 1);
#s = b'kj'
#dll.hello(s, len(s), 1);
#exit()
input = iter('''
1
2 1420
kj
2 1
ik
3 1
kji
2 6
ji
1 10000
i
2 6
ji
2 6
jijj
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

#input  = open(r'C-small-attempt0.in')
#output = open(r'C-small-attempt0-3.out', 'w')

input  = open(r'C-large.in')
output = open(r'C-large.out', 'w')

M = {
'h': {'h':('h',0), 'i':('i',0), 'j':('j',0), 'k':('k',0)},
'i': {'h':('i',0), 'i':('h',1), 'j':('k',0), 'k':('j',1)},
'j': {'h':('j',0), 'i':('k',1), 'j':('h',1), 'k':('i',0)},
'k': {'h':('k',0), 'i':('j',0), 'j':('i',1), 'k':('h',1)},
}

M = [
	['h','i','j','k'],
	['i','h','k','j'],
	['j','k','h','i'],
	['k','j','i','h'],
]

F = [
	[0,0,0,0],
	[0,1,0,1],
	[0,1,1,0],
	[0,0,1,1],
]

def cnv(c, d, f):
	c2 = M[ord(c)-ord('h')][ord(d)-ord('h')]
	f2 = F[ord(c)-ord('h')][ord(d)-ord('h')]
	return c2,(f2+f)%2
	
	

def setup(S):
	global I,K,J
	L = len(S)
	I = [('h',0)]
	
	ci = 'h'
	fi = 0
	for i in range(L-2):
		ci,fi = cnv(ci,S[i],fi)
		I += [(ci,fi)]
	print('yes')	
	K = [('h',0)]
	ck = 'h'
	fk = 0
	for i in range(L-1,-1,-1):
		ck,fk = cnv(S[i],ck,fk)
		K += [(ck,fk)]
	K.reverse()
	print('yes')	
	J = []
	for i in range(L-1):
		X = [('h',0)]
		cj,fj = 'h',0
		for j in range(i,L):
			cj,fj = cnv(S[j],cj,fj)
			X += [(cj,fj)]
		J += [X]
	
	print(I)
	print(K)
	#print(J)
	
			
	#print(I)
	
def cnvs(s):
	c = 'h'
	f = 0
	for d in s:
		c,f = cnv(c,d,f)
	return c,f
	

def solve(S,X):
	print(S)
	setup(S)
	
	#S = S*X
	L = len(S)
	for xi in range(min(X,4)+1):
		for xj in range(min(max(X-xi,0),4)+1):
			for xk in range(min(max(X-xi-xj,0),4)+1):
				for i in range(1,L-1):
					ci,fi = I[i]
					if xj == 0:
						for j in range(i,L-1):
							cj,fj = J[i][j-i]
							ck,fk = K[j]
							print((ci,fi),(cj,fj),(ck,fk))
					else:
						for j in range(L-1):
							cj1,fj1 = K[i]
							cj2,fj2 = I[j]
							ck,fk = K[j]
							print((ci,fi),(cj,fj),(ck,fk))
				
	for i in range(1,L-1):
		ci,fi = I[i]
		if ci != 'i' or fi != 0: continue
		cj,fj = 'h',0
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
	#answer = solve(S,X)
	#print('Case #%d:'%(caseNo+1), answer, file=output)
	answer = dll.solve(S.encode(),L,X)
	print('Case #%d:'%(caseNo+1), 'YES' if answer else 'NO', file=output)
	
print(time.time()-st)