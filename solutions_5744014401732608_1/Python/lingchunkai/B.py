T = int(raw_input())

for t in xrange(T):
	B,M = map(int, raw_input().split())

	if M > 2**(B-2):
		print "Case #" + str(int(t+1)) + ": IMPOSSIBLE"
		continue
		pass # impossible

	# factorize into binary
	L = "{0:b}".format(M)

	sto = [[0]*B for x in xrange(B)]

	# Get largest power of 2
	G = len(L)
	#print "G", G
	for g in range(0,G):
		k=str()

		for q in xrange(B):
			if q == B-1:
				sto[g][q]=1
			elif q <=g: 
				# print "haha", g,q
				sto[g][q]=0
			elif q > G-1:
				sto[g][q]=0
			else: 
				sto[g][q]=1

		# for q in xrange(B):
		# 	if q == B-1:
		# 		k=k+'1'
		# 	elif q <=g: 
		# 		k=k+'0'
		# 	elif q > G:
		# 		k=k+'0'
		# 	else: k=k+'1'

	R = L[1:]
	if all(v==0 for v in R): 
		pass # no need
	#R=int(R, 2)
	else:
		R = list(reversed(R))
		for r in xrange(len(R)):
			if R[r]=='0':continue
			if G==B-1: continue
			sto[r+1][G]=1
		if not G==B-1:
			sto[G][B-1]=1


	print "Case #" + str(int(t+1)) + ": POSSIBLE"
	for b in xrange(B):
		print ''.join(map(str,sto[b]))






