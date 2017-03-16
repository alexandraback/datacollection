# gcj2.py

f = open('B-large.in')
g = open('B-large.out', 'wt')
T = int(f.readline())

for case in range(0, T):
	testcase = f.readline().strip().split()
	maximum = 0
	N = int(testcase.pop(0))
	S = int(testcase.pop(0))
	p = int(testcase.pop(0))
	if p > 1:
		for t in testcase:
			tint = int(t)
			if tint >= 3*p-2:
				maximum += 1
			elif tint >= 3*p-4:
				if S:
					maximum += 1
					S += -1
	elif p == 1:
		for t in testcase:
			tint = int(t)
			if tint >= 1:
				maximum += 1
	elif p == 0:
		for t in testcase:
			maximum += 1
	g.write('Case #' + str(case+1) + ': ' + str(maximum) + '\n')
	
	
	
f.close()
g.close()
	
				
