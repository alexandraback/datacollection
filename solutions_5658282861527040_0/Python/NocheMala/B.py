import sys
import math

def toBin(n):
	arr = []
	while n>0:
		arr.append(n%2)
		n = int(n/2)
	return arr[::-1]
def bitAnd(arr1,arr2):
	arr = []
	for i in range(max(len(arr1),len(arr2))):
		if len(arr1)-1 < i or len(arr2)-1 < i:
			arr.append(0)
		else:
			arr.append(arr1[len(arr1)-i-1]*arr2[len(arr2)-i-1])
	return arr[::-1]
def toInt(arr):
	n = 0
	for i in range(len(arr)):
		n += arr[i]*(2**(len(arr)-1-i))
	return n

def Solve():
	A,B,K = [int(x) for x in my_file.readline().split()]
	cnt = 0
	for i in range(A):
		for j in range(B):
			if i&j < K:
				cnt += 1
	return str(cnt)


def printCase(caseNum,strs):
	sys.stdout.write("Case #"+str(caseNum)+": "+strs+"\n")
	my_file2.write("Case #"+str(caseNum)+": "+strs+"\n")

my_file = open('Input.txt',"r")
my_file2 = open('Output.txt', "w")
N = int(my_file.readline())
for case in range(1,N+1):
	printCase(case,Solve())
my_file.close()
my_file2.close()