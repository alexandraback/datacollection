def getAnswerSmall(N):
	r = ''
	for i in range(int(N[0])):
		r += ' '+str(i+1)
	return r

results=[]
with open('D-small-attempt0.in.txt','r') as f:
   k=0
   for line in f:
        if(k>0):
            N = line.split(' ')
            if(N[2][-1]=='\n'):
            	N[2] = str(N[2][:-1])
            results.append(getAnswerSmall(N))
            if 'str' in line:
                break
        k+=1

with open('answer.txt','wb') as f:
	for i in range(len(results)):
		f.write("Case #"+str(i+1)+":")
		f.write(results[i])
		f.write("\n")

