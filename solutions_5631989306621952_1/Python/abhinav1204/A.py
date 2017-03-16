for z in range(int(input())):
	s=input()
	ans=s[0]
	for i in range(1,len(s)):
		if s[i] >= ans[0]:
			ans=s[i]+ans
		else:
			ans=ans+s[i]
	print("Case #"+str(z+1)+": "+ans)