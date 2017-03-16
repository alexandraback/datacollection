#-*- coding: UTF-8 -*-

case = int(raw_input())
for t in xrange(1, case+1):
	print "Case #{}:".format(t),

	N = int(raw_input())

	left = {}
	right = {}

	queue = []
	answer = 0
	for i in xrange(N):
		l, r = raw_input().split()
		queue.append((l, r))
		if not l in left: left[l] = 0
		if not r in right: right[r] = 0

		left[l] += 1
		right[r] += 1

	answer = 0
	for l, r in queue:
		if left[l] > 1 and right[r] > 1:
			answer += 1

	print answer
