import sys

def dyn(motes, idx, N, armin, moves):
	if idx == N:
		return moves

	if armin <= 1:
		return N

	mote = motes[idx]

	if mote < armin:
		return dyn(motes, idx+1, N, armin+mote, moves)
	else:
		pop = dyn(motes, idx, N-1, armin, moves+1)
		add = dyn(motes, idx, N, armin+armin-1, moves+1)
		return min(pop, add)

def solve():
	armin, N = map(int, sys.stdin.readline().split(' '))

	motes = map(int, sys.stdin.readline().split(' '))
	motes.sort()

	return dyn(motes, 0, len(motes), armin, 0)

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for idx in range(T):
		solution = solve()
		
		print "Case #{}: {}".format(idx+1, solution)
