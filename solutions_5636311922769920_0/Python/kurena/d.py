def func(l,K):
	r = l[0]
	for i in range(1,len(l)): r = (r-1)*K + l[i]
	return r
def solve(K,C,S):
	if K>C*S: return ["IMPOSSIBLE"]
	r=[]
	if S<=C:
		return [str(func([i for i in range(1,S+1)],K))]
	for i in range(S):
		s,t=i*C+1,i*C+C+1
		if i*C+C>S: s,t=S-C+1,S+1
		a=1
		r.append(str(func([j for j in range(s,t)],K)))
		if i*C+C+1>S: break
	return r

testcase = input()
for i in range(testcase):
    print "Case #"+str(i+1)+":",
    K,C,S=map(int,raw_input().split())
    print " ".join(solve(K,C,S))
