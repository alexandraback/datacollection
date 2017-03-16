#!/usr/bin/python

import sys

if len(sys.argv) != 2:
	print "usage: ./b.py <input_file_name>"
	exit()

def compare(a, b, c):
	A = a[:]
	B = b[:]
	for i in xrange(len(A)):
		if c:
			if A[i] == '?':
				A[i] = '0'
			if B[i] == '?':
				B[i] = '9'
		else:
			if A[i] == '?':
				A[i] = '9'
			if B[i] == '?':
				B[i] = '0'
	x = int(''.join(A))
	y = int(''.join(B))
	return abs(x - y), ''.join(A) + ' ' + ''.join(B)

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		S = f.readline()
		S = S[:-1]
		splited = S.split(' ')
		C = list(splited[0])
		J = list(splited[1])
		mindiff = 99999999999999
		ret = ''
		status = 'equal'
		for i in xrange(len(C)):
			if status =='equal':
				if C[i] == '?' and J[i] == '?':
					C[i] = '1'
					J[i] = '0'
					tmpdiff, tmpret = compare(C, J, 1)
					if tmpdiff < mindiff:
						mindiff = tmpdiff
						ret = tmpret
					elif tmpdiff == mindiff and tmpret < ret:
						ret = tmpret
					C[i] = '0'
					J[i] = '1'
					tmpdiff, tmpret = compare(C, J, 0)
					if tmpdiff < mindiff:
						mindiff = tmpdiff
						ret = tmpret
					elif tmpdiff == mindiff and tmpret < ret:
						ret = tmpret
					C[i] = '0'
					J[i] = '0'
				elif C[i] == '?' and J[i] != '?':
					if J[i] != '0':
						C[i] = str(int(J[i]) - 1)
						tmpdiff, tmpret = compare(C, J, 0)
						if tmpdiff < mindiff:
							mindiff = tmpdiff
							ret = tmpret
						elif tmpdiff == mindiff and tmpret < ret:
							ret = tmpret
					if J[i] != '9':
						C[i] = str(int(J[i]) + 1)
						tmpdiff, tmpret = compare(C, J, 1)
						if tmpdiff < mindiff:
							mindiff = tmpdiff
							ret = tmpret
						elif tmpdiff == mindiff and tmpret < ret:
							ret = tmpret
					C[i] = J[i]
				elif C[i] != '?' and J[i] == '?':
					if C[i] != '0':
						J[i] = str(int(C[i]) - 1)
						tmpdiff, tmpret = compare(C, J, 1)
						if tmpdiff < mindiff:
							mindiff = tmpdiff
							ret = tmpret
						elif tmpdiff == mindiff and tmpret < ret:
							ret = tmpret
					if C[i] != '9':
						J[i] = str(int(C[i]) + 1)
						tmpdiff, tmpret = compare(C, J, 0)
						if tmpdiff < mindiff:
							mindiff = tmpdiff
							ret = tmpret
						elif tmpdiff == mindiff and tmpret < ret:
							ret = tmpret
					J[i] = C[i]
				else:
					if int(J[i]) > int(C[i]):
						status = 'Jlarger'
					elif int(C[i]) > int (J[i]):
						status = 'Clarger'
			elif status == 'Jlarger':
				if C[i] == '?':
					C[i] = '9'
				if J[i] == '?':
					J[i] = '0'
			elif status == 'Clarger':
				if J[i] == '?':
					J[i] = '9'
				if C[i] == '?':
					C[i] = '0'
		x = int(''.join(C))
		y = int(''.join(J))
		tmpret = ''.join(C) + ' ' + ''.join(J)
		if abs(x - y) < mindiff:
			ret = tmpret
		elif abs(x - y) == mindiff and tmpret < ret:
			ret = tmpret
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
