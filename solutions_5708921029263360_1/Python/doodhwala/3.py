for cases in range(1, int(input()) + 1):
	pairs = {}
	J, P, S, K = list(map(int, input().split()))
	ans = 0
	combos = []
	f1 = 1
	f2 = 1
	for i in range(1, J+1):
	    for j in range(1, P+1)[::f1]:
	        s1 = 'J{0:d}P{1:d}'.format(i,j)
	        for k in range(1, S+1)[::f2]:
	            s2 = 'J{0:d}S{1:d}'.format(i,k)
	            s3 = 'P{0:d}S{1:d}'.format(j,k)
	            
	            v1 = pairs.get(s1, 0) 
	            v2 = pairs.get(s2, 0)
	            v3 = pairs.get(s3, 0)
	            
	            if(v1 < K and v2 < K and v3 < K):
	                pairs[s1] = v1 + 1
	                pairs[s2] = v2 + 1
	                pairs[s3] = v3 + 1
	                combos.append((i, j, k))
	                ans += 1
	        f2 *= -1
	    f1 *= -1
	        
	# print(pairs)
	print('Case #%d:' % (cases,), ans)
	for combo in combos:
	    print(' '.join([str(x) for x in combo]))
