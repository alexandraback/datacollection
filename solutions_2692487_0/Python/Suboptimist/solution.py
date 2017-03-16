import lib

def solve(A, motes):
	while len(motes)>0 and A>motes[0]:
		A+=motes[0]
		motes.pop(0)
	if len(motes)==0:
		return 0
	# first possibility: add mote
	motes_1 = [m for m in motes]
	motes_1.insert(0, A-1)
	#second possibility: remove mote:
	motes_2 = [m for m in motes]
	motes_2.pop()
	if A==1:
		return 1+solve(A, motes_2)
	else:
		return 1 + min(solve(A, motes_1), solve(A, motes_2))

@lib.wrapper
def solution(input, output):
	T = input.int()
	for case in xrange(T):
		A, N = input.int_tuple()
		motes = input.int_list()
		motes.sort()
		output.result(case+1, solve(A,motes))

if __name__ == '__main__':
	solution()
