numRuns=int(input())
for i in range(numRuns):
	s = input()
	max = s[0]
	for j in range(len(s)-1):
		if s[j+1]<max[0]:
			max+=s[j+1]
		else:
			max=s[j+1]+max
	print("Case #"+str(i+1)+": "+max)