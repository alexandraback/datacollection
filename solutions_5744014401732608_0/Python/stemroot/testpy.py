tc = int(raw_input())
assert(tc>0 and tc<251)

while tc>0:
	tc = tc - 1
	S,P = raw_input().split()
	flag = 0
	assert (len(S)<61)
	assert (len(P)<61)
	for i in range(len(S)):
		current = S[0:i] + S + S[i:]
		if current == P:
			flag = 1
			break
		else:
			flag = 0
	if flag == 1:
		print "Possible"
	else:
		print "Impossible"   	
