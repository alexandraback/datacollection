t = int(raw_input())
for i in range(1,t+1):
	S = raw_input()
	ans = S[0]
	length = len(S)
	for letter in xrange(1,length):
		#print letter
		if(S[letter] >= ans[0]):
			ans = S[letter]+ans
		else:
			ans = ans+S[letter]
	print ("Case #"+str(i)+": "+ans)
