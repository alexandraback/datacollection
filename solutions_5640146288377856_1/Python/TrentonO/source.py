# A Small
def solve(rows, columns, ship_length):
	return columns/ship_length*rows + ship_length - 1 + (columns % ship_length != 0)







#############################################################

inF = open('test.in')
case_sols = []
for case in xrange(int(inF.readline())):
	rows, columns, ship_length = map(int, inF.readline().split())
	case_sols.append(solve(rows, columns, ship_length))

inF.close()

B_sol = open('solution.txt', 'w')
for i, sol in enumerate(case_sols, start=1):
	B_sol.write('Case #{0}: '.format(i) + str(sol) + '\n')

B_sol.close()