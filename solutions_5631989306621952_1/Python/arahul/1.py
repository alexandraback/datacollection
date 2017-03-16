t=int(raw_input())
case=0
for _ in range(t):
	case+=1
	s=raw_input()
	ans=s[0]
	for i in range(1,len(s)):
		if ord(ans[0])<=ord(s[i]):
			ans=s[i]+ans
		else:
			ans=ans+s[i]
	print ("Case #"+str(case)+": "+ans)
