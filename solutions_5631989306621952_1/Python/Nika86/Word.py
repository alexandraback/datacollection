#! /usr/bin/python

T = int(raw_input())

for t in range(1, T+1):

	
	S = raw_input().strip()
	W = [S[0]]

	for i in range(1, len(S)):
		if S[i] >= W[0]:
			W = [S[i]] + W
		else:
			W += [S[i]]

	print 'Case #' + str(t) + ': ' + ''.join(W)