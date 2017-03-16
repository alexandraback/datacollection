import sys
glmax = 0


def recurse(boxqq, toyqq, matched):
	global glmax
	if matched > glmax:
		glmax = matched
	if len(boxqq) == 0 or len(toyqq) == 0:
		return
	
	boxq = list(boxqq)
	toyq = list(toyqq)
	if boxq[0][0] == 0:
		boxq.pop(0)
	if toyq[0][0] == 0:
		toyq.pop(0)
	if len(boxq) == 0 or len(toyq) == 0:
		return
	
	
	if boxq[0][1] == toyq[0][1]:
		canuse = min(boxq[0][0], toyq[0][0])
		boxq[0][0] -= canuse
		toyq[0][0] -= canuse
		recurse(boxq, toyq, matched + canuse)
		toyq[0][0] += canuse
		boxq[0][0] += canuse
	else:
		a = toyq.pop(0)
		recurse(boxq, toyq, matched)
		toyq.insert(0, a)
		b = boxq.pop(0)
		recurse(boxq, toyq, matched)
		boxq.insert(0, b)

def solve(boxes, toys):
	bq = []
	tq = []
	for i in range(0, len(boxes), 2):
		bq.append([boxes[i], boxes[i+1]])
	for i in range(0, len(toys), 2):
		tq.append([toys[i], toys[i+1]])
	global glmax 
	glmax = 0
	recurse(bq, tq, 0)
	return glmax
	
if __name__ == '__main__':
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('c.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		g = fin.readline().strip().split(' ')
		n = int(g[0])
		m = int(g[1])
		g = fin.readline().strip().split(' ')
		nn = [int(k) for k in g]
		g = fin.readline().strip().split(' ')
		mm = [int(k) for k in g]
		ss = 'Case #%d:'%(i+1) + ' ' + str(solve(nn, mm))
		print ss
		fout.write(ss+'\n')
	fout.close()
