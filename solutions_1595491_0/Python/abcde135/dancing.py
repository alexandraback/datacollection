def write_case(n, s, f):
    f.write("Case #%i: %s\n" % (n, s))

# can a googler with total points t
#  have a best result of at least p
#  without surprise
# t: total points
# p: minimum best result
def win_without_surprise(t, p):
	if t % 3 == 0:
		return t / 3 >= p
	else:
		return t / 3 + 1 >= p

# can a googler with total points t
#  have a best result of at least p
#  with surprise
def win_with_surprise(t, p):
	if t == 0:
		return p <= 0
	elif t % 3 == 2:
		return t / 3 + 2 >= p
	else:
		return t / 3 + 1 >= p

# L: list of total points
# S: number of surprises
# p: minimum best result
def total_win(L, S, p):
	total = 0
	surprise_left = S
	for t in L:
		if win_without_surprise(t, p):
			total += 1
		elif win_with_surprise(t, p) and surprise_left > 0:
			total += 1
			surprise_left -= 1

	return total

def solve(infilename, outfilename):
	f = open(infilename)
	g = open(outfilename, 'w')
	
	T = int(f.readline())

	for n in range(T):
		L = [int(x) for x in f.readline().split()]
		S = L[1]
		p = L[2]
		L = L[3:]
		total = total_win(L, S, p)
		write_case(n+1, str(total), g)

	f.close()
	g.close()

if __name__ == "__main__":
#	solve('dancing-sample.in', 'dancing-sample.out')
	solve('B-small-attempt0.in', 'B-small-attempt0.out')
