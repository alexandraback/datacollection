T = int(raw_input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case

for K in range (T):
	J,P,S,k= [int(s) for s in raw_input().split(" ")]

	dic1 = {}
	dic2 = {}
	dic3 = {}
	res = []

	for i in xrange(J):
		for j in xrange(P):
			for g in xrange(S):
				t = (j + g + 1) % S
				a = j * 10 + t
				b = i * 10 + t
				c = i * 10 + j

				if (a in dic1) and (dic1[a] >= k):
					continue
				if (b in dic2) and (dic2[b] >= k):
					continue
				if (c in dic3) and (dic3[c] >= k):
					continue

				if a in dic1:
					dic1[a] += 1
				else:
					dic1[a] = 1

				if b in dic2:
					dic2[b] += 1
				else:
					dic2[b] = 1

				if c in dic3:
					dic3[c] += 1
				else:
					dic3[c] = 1

				ans = str(i+1) + ' ' + str(j+1) + ' ' + str(t+1)
				res.append(ans)

	print "Case #{}: {}".format(K+1, len(res))
	for ans in res:
		print(ans)

				
				
				

