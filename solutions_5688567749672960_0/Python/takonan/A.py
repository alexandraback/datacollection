import os, sys, time, math

def flip(N):

	return int(str(N)[::-1])

def genTable(N):
	table = [10**6] * (10**6 + 1)
	table[0] = 10**6+1
	for i in range(1, 21):
		table[i] = i
	for i in range(21, len(table)):
		if i % 10 != 0:
			table[i] = min(table[flip(i)] + 1, table[i-1] + 1)
		else:
			table[i] = table[i - 1] + 1
	print table[1:35]
	return table

# def solve(N):
# 	answer = N
# 	if N < 15:
# 		return N
# 	else:
# 		A = solve(N-1) + 1
# 		print "A: ", A
# 		if (N % 10 != 0) and flip(N) < N:
# 			B = solve(flip(N)) + 1
# 			answer = min(A, B)
# 			print "B: ", B
# 		else:
# 			answer = A

# 	print "Answer for N=", N, ":", answer
# 	return answer

# def solve(N):
# 	value = 1
# 	count = 1

# 	while value != N:
# 		if (flip(value) > (value + 1)) and flip(value) <= N:
# 			value = flip(value)
# 		else:
# 			value += 1
# 		count += 1

# 	answer1 = count

# 	# Do with flip:
# 	value = 1
# 	count = 1

# 	while value != flip(N):
# 		if (flip(value) > (value + 1)) and flip(value) <= flip(N):
# 			value = flip(value)
# 		else:
# 			value += 1
# 		count += 1

# 	answer2 = count + 1

# 	return min(answer1, answer2)

def main(fin, fout):
	T = int(fin.readline())
	table = genTable(10**6)
	for t in range(T):
		N = int(fin.readline().strip())
		print "Starting case #", (t+1), N
		answer = table[N]
		print "Case #%d: %d" % (t+1, answer)
		fout.write("Case #%d: %d\n" % (t+1, answer))
	return

if __name__ == '__main__':
	sys.setrecursionlimit(10000)
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	start = time.time()
	main(fin, fout)
	print time.time() - start