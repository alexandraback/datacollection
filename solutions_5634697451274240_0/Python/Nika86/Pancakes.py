#! /usr/bin/python

T = int(raw_input())

for t in range(1, T+1):

	S = raw_input() + '+'
	
	inversions = 0
	for i in range(len(S) - 1):
		inversions += (S[i] != S[i+1])

	print 'Case #' + str(t) + ': ' + str(inversions)