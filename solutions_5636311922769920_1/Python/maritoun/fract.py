def getAnswerSmall(N):
	r = ''
	for i in range(int(N[0])):
		r += ' '+str(i+1)
	return r

def getAnswerBig(N):
	#K base
	#C longueur des nombres
	#S la quantite de nombres
	K,C,S = [int(l) for l in N]
	#ecriture des nombres en liste, but couvrir tous les K
	#condition quantite de digits parcourables est C*S>=K
	if(C*S<K):
		return 'IMPOSSIBLE'
	else: #possible
		i = 0
		r = ''
		while i < K:
			nombre = 0
			for j in range(C)[::-1]:
				nombre += min(i,K-1)*(K**j)
				i += 1
			r += ' '+str(nombre+1)
		return r
	return None

results=[]
with open('D-large.in.txt','r') as f:
   k=0
   for line in f:
        if(k>0):
            N = line.split(' ')
            if(N[2][-1]=='\n'):
            	N[2] = str(N[2][:-1])
            results.append(getAnswerBig(N))
            if 'str' in line:
                break
        k+=1

with open('answer.txt','wb') as f:
	for i in range(len(results)):
		f.write("Case #"+str(i+1)+":")
		f.write(results[i])
		f.write("\n")

