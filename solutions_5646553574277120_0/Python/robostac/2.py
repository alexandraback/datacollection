import sys

num_cases = int(sys.stdin.readline())

def update_list(vals,coins,coin,v):


	for i in xrange(len(vals) -1 , -1, -1):
		if (vals[i] == 1):
			if (i + coin) < v:
				vals[i + coin] = 1
	vals[coin-1] = 1
	coins.append(coin)
	return vals

def gen_list(b,v):
	vals = [0] * v
	coins = [];
	while len(b) > 0:
		coin = b.pop()
		m = 0
		vals = update_list(vals,coins,coin,v)

	return vals

def result(a,b):
	a = map(int,a.split(" "))
	b = map(int,b.split(" "))
	maxcount = a[0]
	v = a[2]
	vals = [0] * v
	count = 0
	vals = gen_list(b[:],v)
	for i in xrange(0,v):
		if (vals[i] == 0):
			count += 1

			for j in xrange(0,maxcount):

				vals = update_list(vals,b,(j+1)*(i+1),v)
	return str(count)



for i in range(1,num_cases+1):
	print "Case #" + str(i) + ": " + result(sys.stdin.readline(),(sys.stdin.readline()))
