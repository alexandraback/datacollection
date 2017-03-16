#!/usr/bin/python 

import sys
import copy
import re

def RF(numbers_str):
	return [float(x) for x in numbers_str]
def DB (A,B,l):
	B.sort()
	A.sort()
	
	for k in range(l) :
		f = True
		for i in range(l-k) :
			if A[i+k] < B[i] :
				f = False
		if f == True:
			return l-k
	return 0
def BB (A,B,l):
	B.sort()
	A.sort()
	c = 0
	for k in range(l) :
		if B[k] < A[k] :
			c+=1
	return c
	
def read_s(s):
	tmp = s[0]
	tmp_count = 1
	B = []
	C = {}
	i = 1
	while i < len(s) :
		if s[i] == tmp :
			tmp_count+=1 
		else :
			B.append(tmp)
			B.append(tmp_count)
			tmp = s[i]
			tmp_count = 1
		i+=1
	return B

def sum_moves(D) :
	mx = max(D)
	mn = min(D)
	if mx == mn :
		return 0
	i = 0
	count_mn = 0
	count_mx = 0
	b1 = -1
	b2 = -1
	B_mx  =[]
	B_mn = []
	while i < len(D) :
		if D[i] == mx :
			mx_ind = i
			B_mx.append(i)
			count_mx +=1
		if D[i] == mn :
			mn_ind = i
			B_mn.append(i)
			count_mn +=1
		i+=1
	#if count_mn > count_mx :			 
	for jj in B_mx :
		D[jj] -=1
	tmp11 = 1 + sum_moves(D)
	#else :
	for jj in B_mn :
		D[jj] +=1
	for jj in B_mx :
		D[jj] +=1
	return min(tmp11, 1 + sum_moves(D))
		
def sum_moves_mod(D):
	count_D = 0
	for i in D :
		count_D +=i
	count_D = float(count_D / len(D))
	count_dif = 0.0
	for i in D :
		count_dif += abs(i - count_D)
	return int(count_dif)	

def sum_moves_mod2(D):
	BST = 10000000
	for i in D :
		goal = i
		tmp_sum = 0
		for j in D :
			tmp_sum +=abs(j-i)
		BST = min(BST,tmp_sum)
		
	return BST
	
def compute_A(A) :
	L = len(A[0])
	C = []
	for i in A:
		if len(i) != L :
			return -1
	j = 0
	while j < len(A[0]) :
		 C.append(A[0][j])
		 j+=2
	for i in A : 
		j = 0
		k = 0
		while j <len(A[0]) :
			if i[j] != C[k] :
				return -1
			j +=2
			k +=1
	sum_c = 0
	j = 1 
	while j < len(A[0]) :
		DD = []
		for kk in A :
			DD.append(kk[j])
		#print sum_moves(DD)
		sum_c += sum_moves_mod(DD)
		j+=2
	return sum_c

def gcd(a,b):
	if (b>a) :
		return gcd(b,a)
	if b == 0 or a == b :
		return a
	else :
		return gcd(b,a%b)
def anc(p,q):
	g = gcd(p,q)
	m1 = p/g
	m2 = q/g
	if m2 == m1 :
		return 1
	A = [] 
	k = 0
	while k < 42 :
		A.append(pow(2,k))
		k+=1
	if m2 not in A :
		return -1
	else :
		j = 0
		#print A
		#print m1
		#print m2
		while j+1 < len(A) :
			if  m1>=A[j] and m1 < A[j+1] :
				c1 = j
			if m2 == A[j] :
				c2 = j
			j+=1
		return c2 - c1 
			
		 
				
			 
	
def main():
	T = int(sys.stdin.readline().strip())
	for i in range(T):
		s = sys.stdin.readline()
		number_str = re.split('\/',s)
		r = int(number_str[0])
		c = int(number_str[1]) 
		#print A
		res = anc(r,c) 	 
		sys.stdout.write('Case #{}: '.format(i+1))
		#print resd
		if res == -1 :
			sys.stdout.write('impossible')
		else:
			sys.stdout.write('%d ' %res)
		sys.stdout.write('\n')	
        
        
        

if __name__ == '__main__':
	main()
