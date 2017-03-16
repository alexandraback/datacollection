import numpy as np

def CheckBinaryForm(P, Q, limit):
	if P == 0:
		return []

	if limit == 0:
		return ["dead"]

	if P >= Q:
		return [1] + CheckBinaryForm(2*(P-Q), Q, limit-1)
	else:
		return [0] + CheckBinaryForm(2*P, Q, limit-1)


def ProcessOne():
	N = raw_input().split("/")
	P = int(N[0])
	Q = int(N[1])

	form = CheckBinaryForm(P,Q, 41)

	if form[-1] == "dead":
		print ("Case #%(id)s: %(res)s" % {"id" : i+1, "res" : "impossible"})
	else:
		# Find first one
		firstone = form.index(1)
		print ("Case #%(id)s: %(res)s" % {"id" : i+1, "res" : firstone})
		


T = int(raw_input())

for i in range(T):
	ProcessOne()




