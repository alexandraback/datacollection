
mem = [0, 1]

for N in xrange(2, 10**6+1):
	r = int(str(N)[::-1])
	if r >= N or len(str(r)) < len(str(N)):
		mem.append(1 + mem[N-1])
	else:
		mem.append(min(1 + mem[r], 1 + mem[N-1]))

inF = open('A_small.in')
case_sols = []
for case in xrange(int(inF.readline())):
	case_sols.append(mem[int(inF.readline())])

inF.close()

A_small_sol = open('A_small_sol.txt', 'w')
for i, sol in enumerate(case_sols):
	A_small_sol.write('Case #{0}: '.format(i+1) + str(sol) + '\n')

A_small_sol.close()