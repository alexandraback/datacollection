def findCircle(S):
	max_circle = 0
	for i in range(0, len(S)):
		res = []
		ff = i
		res.append(ff)
		# print ff, res
		while True:	
			bff = S[ff]
			# print res, bff
			if bff in res:
				try: 
					dff = S[bff+1:].index(ff) + bff + 1
					# print 'dff', S[bff+1:], dff
				except:
					break
				if bff != dff and not dff in res:
					res.append(dff)
					ff = dff
				else:
					try: 
						dff = S[0:bff].index(ff)
						# print 'dff', S[0:bff], dff
						# print 'dff', dff
					except:
						break
					if bff != dff and not dff in res:
						res.append(dff)
						ff = dff
					else:
						break
			else:
				res.append(bff)
				ff = bff
		if S[res[len(res)-1]] != res[0] and S[res[len(res)-1]] != res[len(res)-2]:
			k = res.pop(len(res)-1)
			# print "poped", k
		if len(res) > max_circle:
			max_circle = len(res)
	return max_circle

T = int(raw_input().strip())

for i in range(0, T):
	N = int(raw_input().strip())
	S = map(int, raw_input().strip().split(" "))
	for s in range(0, len(S)):
		S[s] = S[s]-1
	# print S
	print "Case #" + str(i+1) + ':', findCircle(S)