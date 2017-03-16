import lib
import math

def fill(right, wrong, layer, remaining, y):
	if right == y:
		return 1.0
	if remaining == 0:
		return 0.0
	if wrong == 2*layer:
		return 1.0 if y-right<=remaining else 0.0
	return 0.5*(
		fill(right+1,wrong,layer,remaining-1,y)
		+fill(right,wrong+1,layer,remaining-1,y))

@lib.wrapper
def solution(input, output):
	T = input.int()
	for case in xrange(T):
		N, X, Y = input.int_tuple()
		# check, to which layer this position belongs:
		layer = (abs(X)+Y)/2
		# calc how many layers can be safely filled
		safe = int(0.5*math.sqrt(2*N+0.25)-0.75)
		if layer <= safe:
			probability = 1.0
		elif layer > safe+1:
			probability = 0.0
		elif X == 0:
		 	probability = 0.0
		else:
			a = 2*safe+1
			remaining_blocks = N - (a*a+a)/2
			if remaining_blocks>layer*2 and remaining_blocks-2*layer>Y:
				probability = 1.0
			else: 
				probability = fill(0,0,layer,remaining_blocks,Y+1)
		output.result(case+1, probability)
		

if __name__ == '__main__':
	solution()
