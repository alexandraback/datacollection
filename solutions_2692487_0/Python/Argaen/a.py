#encoding: UTF-8
T = int(raw_input())

for case in range(T):
	line = raw_input().split(' ')
	a, n = int(line[0]), int(line[1])
	motes = [int(i) for i in raw_input().split(' ')]
	motes.sort()

	sePuede = True
	t = a
	k = 0
	maxk = n+2
	for i in range(n):
		if motes[i] < t:
			t += motes[i]
		else:
			k += 1
			if motes[i]<2*t-1:
				t = 2*t-1 + motes[i]
			else:
				if maxk==n+2: maxk = n-i-1+k
				tt = t
				for j in range(n-i-1):
					tt = 2*tt-1
					if motes[i]<tt:
						k += j
						t = tt + motes[i]
						break
	print 'Case #'+str(case+1)+':', min([k, maxk])

