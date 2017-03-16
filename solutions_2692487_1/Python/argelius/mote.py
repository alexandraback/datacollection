import sys

memory = {}

def dyn(motes, idx, N, armin):
	if idx == N:
		return 0

	if armin <= 1:
		return N

	try:
		a = memory[idx, N, armin]
	except KeyError:
		pass
	else:
		return a

	mote = motes[idx]

	if mote < armin:
		ret = dyn(motes, idx+1, N, armin+mote)
	else:
		pop = 1+dyn(motes, idx, N-1, armin)
		add = 1+dyn(motes, idx, N, armin+armin-1)
		ret = min(pop, add)

	memory[idx, N, armin] = ret
	return ret

def solve():
	armin, N = map(int, sys.stdin.readline().split(' '))

	motes = map(int, sys.stdin.readline().split(' '))
	motes.sort()

	global memory
	memory = {}
	return dyn(motes, 0, len(motes), armin)

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for idx in range(T):
		solution = solve()
		
		print "Case #{}: {}".format(idx+1, solution)
