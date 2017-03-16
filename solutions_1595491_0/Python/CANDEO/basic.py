import sys
from math import *

input_list = []
output_list = []

try:
	input_filename = sys.argv[1]
	output_filename = input_filename[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	input_f = open("./"+input_filename)
	input_lines = input_f.readlines()
	input_count = 0
	for input_line in input_lines:
		input_split = input_line.split()
		input_list.append(input_split)
	input_f.close()
except:
	print 'read error'
	exit()

input_list.pop(0)

def getNormalMax(t):
	if t % 3 == 0:
		return t / 3
	elif t % 3 == 1:
		return floor(t / 3) + 1
	elif t % 3 == 2:
		return floor(t / 3) + 1

def getSurpMax(t):
	if t == 0:
		return 0
	elif t % 3 == 0:
		return floor(t / 3) + 1
	elif t % 3 == 1:
		return floor(t / 3) + 1
	elif t % 3 == 2:
		return floor(t / 3) + 2

def getAnswer(N, S, P, T):
	A = 0
	B = 0
	for x in range(N):
		t = int(T[x])
		print 't:', t
		if getNormalMax(t) >= P:
			print 'normal >= p'
			A = A + 1
		elif getSurpMax(t) == P:
			print 'surp = p'
			B = B + 1
	print N, A, B, S
	return A + min(B, S)


for input_line in input_list:
	N = int(input_line[0])
	S = int(input_line[1])
	P = int(input_line[2])
	T = input_line[3:]
	
	result = getAnswer(N, S, P, T)
	output_list.append([result])

try:
	output_f = open("./"+output_filename, "w")
	output_f.close()
except:
	pass

try:
	output_f = open("./"+output_filename, "a")
	output_str = ''

	for x in range(len(output_list)):
		output_f.write('Case #' + str(x+1)+': '+str(output_list[x][0])+"\n")
		print x
	output_f.close()
except:
	print 'write error'
	exit()
