#!/usr/bin/python


T=int(raw_input())
for t in range(T):
	L=list(map(int, raw_input().split()))
	N=L[0]
	SI=L[1:]
	S=sum(SI)
	for i in range(len(SI)):
		SI[i] = 1.0*SI[i] / S

	P=1.0
	M=[ 0.0 for i in range(N)]
	D=[ 0.0 for i in range(N)]
	
	while P > 0.0:
		msi  = min(SI)
		mpos = [SI[i] == msi for i in range(N)]
		msic = sum(mpos)
		msiv = 1.0
		for i in range(N):
			if mpos[i] == False and SI[i] < msiv:
				msiv = SI[i]
		diff = (msiv - msi)
		inc = min(diff, P/msic)
		P -= msic*inc
		for i in range(N):
			if mpos[i] == True:
				D[i] += inc
				SI[i] += inc
			
	SS = ""
	for m in D:
		SS = SS + " %.6f" % (m*100)
	print "Case #%d: %s" % ((t+1),SS)
