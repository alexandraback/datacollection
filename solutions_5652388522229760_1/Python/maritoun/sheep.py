def getAnswer(N):
	if(N==0):
		return 'INSOMNIA'
	else:
		i=0
		li=[]
		while(len(li)<10):
			i+=N
			dec=str(i)
			for j in dec:
				if(not j in li):
					li.append(j)
		return i
	return 0

results=[]
with open('A-large.in.txt','r') as f:
   k=0
   for line in f:
        if(k>0):
            N = int(line)
            results.append(getAnswer(N))
            if 'str' in line:
                break
        k+=1

with open('answer.txt','wb') as f:
	for i in range(len(results)):
		f.write("Case #"+str(i+1)+": ")
		f.write(str(results[i]))
		f.write("\n")

