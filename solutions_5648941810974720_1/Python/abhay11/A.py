let = ['Z','W','X','U','F','V','O','G','I','T']
num = [0, 2, 6, 4, 5, 7, 1, 8, 9, 3]
name = ['ZERO','TWO','SIX','FOUR','FIVE','SEVEN','ONE','EIGHT','NINE','THREE']

numRuns=int(input())
for run in range(numRuns):
	s = input()
	a = [0]*10
	for i in range(10):
		a[num[i]]=s.count(let[i])
		for ch in name[i]:
			s=s.replace(ch,'',a[num[i]])
	output=''
	for i in range(10):
		while (a[i]>0):
			output+=str(i)
			a[i]-=1
	print("Case #"+str(run+1)+": "+output)
