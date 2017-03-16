
import sys
import time
import operator
import math
import re
import heapq
from collections import deque

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('B-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/B-small-attempt3.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/B-large.in', 'r')

def main():
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")



def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def f(Ct):
	for k in  range(len(Ct)):
		C = Ct[k]
		for i in range(len(C)):
			if C[i] == '?':
				Ct[k]=C[:i] + '0' + C[i+1:]
				for j in range(1,10):
					Ct.append(C[:i] + str(j) + C[i+1:])
				return True
	return False

def doCase(case):
	C, J = inFile.readline().split()
	Ct = [C]
	Jt = [J]
	while f(Ct):
		pass
	while f(Jt):
		pass
	mc = Ct[0]
	mj = Jt[0]
	for c in Ct:
		for j in Jt:
			if abs(int(mc) - int(mj)) > abs(int(c) - int(j)):
				mc = c
				mj = j
			elif abs(int(mc) - int(mj)) == abs(int(c) - int(j)) and int(c) < int(mc):
				mc = c
				mj = j
			elif abs(int(mc) - int(mj)) == abs(int(c) - int(j)) and int(c) == int(mc) and  int(j) <= int(mj):
				mc = c
				mj = j
	

	out(mc+' '+mj)

	return

def doCase1(case):
	C, J = inFile.readline().split()
	n = len(C)
	C2 = None
	for i in range(n):
		if C[i] != J[i] and C[i] != '?' and J[i] != '?':
			break
		if C[i] == '?' and J[i] == '?':
			if i == n - 1 or (C[i+1] == J[i+1]):
				C = C[:i] + '0' + C[i+1:]
				J = J[:i] + '0' + J[i+1:]
			elif C[i+1] == '?' and J[i+1] <= '8':
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
			elif J[i+1] == '?' and C[i+1] <= '8':
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
			elif C[i+1] == '?':
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
				J2 = J[:i] + '0' + J[i+1:]
				C2 = C[:i] + '10' + C[i+2:]
			elif J[i+1] == '?':
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
				J2 = J[:i] + '10' + J[i+2:]
				C2 = C[:i] + '0' + C[i+1:]
			elif C[i+1] < J[i+1]:
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
				J2 = J[:i] + '0' + J[i+1:]
				C2 = C[:i] + '1' + C[i+1:]
			elif J[i+1] < C[i+1]:
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]
				J2 = J[:i] + '1' + J[i+1:]
				C2 = C[:i] + '0' + C[i+1:]
			else:
				J = J[:i] + '0' + J[i+1:]
				C = C[:i] + '0' + C[i+1:]


		elif C[i] == '?':
			if i < n - 1 and J[i+1]!='?' and C[i+1]!='?' and abs(int(J[i+1])-int(C[i+1])) >= 5:
				if C[i+1] < J[i+1]:
					C2 = C[:i] + str(int(J[i]) + 1) + C[i+1:]
					J2 = J
				else:
					C2 = C[:i] + str(int(J[i]) - 1) + C[i+1:]
					J2 = J
			C = C[:i] + J[i] + C[i+1:]


		elif J[i] == '?':
			H = J
			J = C
			C = H
			if i < n - 1 and J[i+1]!='?' and C[i+1]!='?' and  abs(int(J[i+1])-int(C[i+1])) >= 5:
				if C[i+1] < J[i+1]:
					J2 = C[:i] + str(int(J[i]) + 1) + C[i+1:]
					C2 = J
				else:
					J2 = C[:i] + str(int(J[i]) - 1) + C[i+1:]
					C2 = J
			C = C[:i] + J[i] + C[i+1:]

			H = J
			J = C
			C = H

	if not '?' in C and not '?' in J and C2 == None:
		out(C+' '+J)
		return
	if 0:
		print(C)
		print(J)
		print(C2)
		print(J2)
	m = C[:i-1] == min(C[:i-1], J[:i-1])
	if not m:
		H = C
		C = J
		J = H

	for i in range(n):
		if C[i] == '?':
			C = C[:i] + '9' + C[i+1:]
		if J[i] == '?':
			J = J[:i] + '0' + J[i+1:]

	if not m:
		H = C
		C = J
		J = H
	if C2 == None:
		out(C+' '+J)
		return 

	m = C2[:i-1] == min(C2[:i-1], J2[:i-1])
	if not m:
		H = C2
		C2 = J2
		J2 = H

	for i in range(n):
		if C2[i] == '?':
			C2 = C2[:i] + '9' + C2[i+1:]
		if J2[i] == '?':
			J2 = J2[:i] + '0' + J2[i+1:]

	if not m:
		H = C2
		C2 = J2
		J2 = H
	if 0:
		print(C)
		print(J)
		print(C2)
		print(J2)
	if abs(int(C) - int(J)) < abs(int(C2) - int(J2)):
		out(C+' '+J)
		return
	if abs(int(C) - int(J)) > abs(int(C2) - int(J2)):
		out(C2+' '+J2)
		return
	if int(C) < int(C2):
		out(C+' '+J)
		return
	if int(C) > int(C2):
		out(C2+' '+J2)
		return
	if int(J) < int(J2):
		out(C+' '+J)
		return
	out(C2+' '+J2)


	


def debugln(m):
	debug(m)
	debug('\n')

def debug(m):
	if debugv:
		sys.stdout.write(str(m))

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 