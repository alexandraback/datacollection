n = 32
J = 500
print("Case #1:")
cnt = 0
alr = []

for i in range(1,15):
	for j in range(i+1,n-i):
		for k in range(j+1,n-i):
			vr = []
			for x in range(n):
				vr.append('0')
			vr[0] = '1'
			vr[i] = '1'
			vr[n-i-1] = '1'
			vr[n-1] = '1'
			vr[j] = '1'
			vr[j+i] = '1'
			vr[k] = '1'
			vr[k+i] = '1'
			onec = 0
			for x in range(n):
				if(vr[x]=='1'):
					onec = onec + 1
			if(onec%2!=0):
				continue
			s = "".join(vr)
			if(s not in alr and cnt<J):
				print(s,end=' ')
				alr.append(s)
				cnt = cnt+1
				for d in range(2,11):
					print((1+d**i),end=' ')
				print()