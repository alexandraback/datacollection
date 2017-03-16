def reverse_digits(N):
	return int((str(N))[::-1])


# def solve(N):
# 	curr_jumps = 1
# 	min_jumps = N
# 	pos = [1]
# 	while curr_jumps < min_jumps:
# 		new_pos = []
# 		for p in pos:
# 			new_pos.append(p+1)
# 			rp = reverse_digits(p)
# 			if rp > p:
# 				if rp <= N:
# 					new_min_jumps = curr_jumps + 1 + N - rp
# 					if new_min_jumps < min_jumps:
# 						min_jumps = new_min_jumps
# 					new_pos.append(rp)
# 		pos = new_pos
# 		curr_jumps += 1
# 		# print pos, curr_jumps, min_jumps
# 	return str(min_jumps)


# def make_table(N):
# 	table = [i+1 for i in range(N)]
# 	steps = 1
# 	i = 0
# 	while i < N:
# 	# for i in range(N):
# 		if table[i] < steps:
# 			steps = table[i]
# 		else:
# 			table[i] = steps
# 		n = i + 1
# 		rn = reverse_digits(n);
# 		if rn <= N and table[rn-1] > steps + 1:
# 			table[rn-1] = steps + 1
# 			if rn > n:
# 				i += 1
# 			else:
# 				i = rn - 1
# 		# print n, steps, table
# 		steps += 1
# 	return table


def make_table(N):
	table = [N+1 for i in range(N+1)]
	table[0] = 0
	table[1] = 1
	pos = set([1])
	for steps in range(1, N+1):
		new_pos = []
		for p in pos:
			pn = p + 1
			if pn < N and table[pn] > steps + 1:
				table[pn] = steps + 1
				new_pos.append(pn)
			pr = reverse_digits(p)
			if pr < N and table[pr] > steps + 1:
				table[pr] = steps + 1
				new_pos.append(pr)
		pos = set(new_pos)
		# print steps, table
	return table

# def solve(N):
	# table = [i for i in range(N)]

################################################################################

from sys import argv, exit

if len(argv) != 3:
	print "Usage: python main.py <input file> <output file>";
	exit(1);

ifile = open(argv[1])
ofile = open(argv[2], "w")

T = int(ifile.readline())

# print T

table = make_table(2000000);
# table = make_table(1000);
# for i in range(1, 101):
# 	print i, table[i]

for i in range(1, T+1):
	N = int(ifile.readline().strip());
	# ms = [int(s) for s in ifile.readline().strip().split()]

	res = str(table[N]);

	output = 'Case #' + str(i) + ': ' + res

	# print output

	# print "------------------------------"

	ofile.write(output)
	ofile.write('\n')
