import fileinput
stdin = fileinput.input()

def nextNums(n):
	r = 0
	m = n
	while m>0:
		r *= 10
		r += m%10
		m /= 10
	return [n+1,r]

def prevNums(n):
	r = 0
	m = n
	while m>0:
		r *= 10
		r += m%10
		m /= 10
	if r!=n and n%10!=0:
		yield r
	yield n-1

def turns(n):
	t = 1
	done = {n}
	buff = [n]
	while 1 not in done:
		t += 1
		buff = [ i for b in buff for i in prevNums(b) if i not in done and all(i<=1.1*p for p in prevNums(b))]
		done |= set(buff)
	return t

def solveCase():
	n = map(int,stdin.next().split())[0]
	return turns(n)

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())