import math

def solve(A, N, B):
	if A == 1:
		return N
	else:
		B = [int(b) for b in B]
		B.sort()
		add_list = []
		remove_list = [N-i for i in range(N)]
		current_A = A
		for i in range(N):
			if current_A > B[i]:
				current_A = current_A + B[i]
				if i == 0:
					add_list = [0]
				else:
					add_list.append(add_list[i-1])
			else:
				if i == 0:
					add_list = [0]
				else:
					add_list.append(add_list[i-1])
				while current_A <= B[i]:
					add_list[i] = add_list[i] + 1
					current_A = current_A * 2 - 1
				current_A = current_A + B[i]

		result_list = [remove_list[0], add_list[N-1]]
		for i in range(N - 1):
			result_list.append(remove_list[i+1] + add_list[i])
		return min(result_list)

def is_palindrome(x):
	return str(x) == str(x)[::-1]

File = open("A-small-attempt0.in", "r")
f = []
for line in File:
	f.append(line.split())
for i in range(int(f[0][0])):
	A = int(f[2*i+1][0])
	N = int(f[2*i+1][1])
	B = f[2*i+2]
	print "Case #%d:" %(i+1), solve(A, N, B)