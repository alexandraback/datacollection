
def executer_calcul(entrees):
	N=entrees[0]
	word1=entrees[1]
	word2=entrees[2]
	Case=entrees[3]
	return str(calcul(N,word1,word2,Case))

def calcul(N,word1,word2,Case):
	if(N<=1): return 0
	dict1={}
	dict2={}
	copie1=[] # On ne supprime pas deux fois un même mot lors d'une passe
	copie2=[]
	for i in range(N):
		if (hash(word1[i]) in dict1): dict1[hash(word1[i])]=dict1[hash(word1[i])]+1
		else: dict1[hash(word1[i])]=1
		if (hash(word2[i]) in dict2): dict2[hash(word2[i])]=dict2[hash(word2[i])]+1
		else: dict2[hash(word2[i])]=1
	for i in range(N):
		if(dict1[hash(word1[i])]>1 and dict2[hash(word2[i])]>1):
			copie1.append(i)
			copie2.append(i)
			dict1[hash(word1[i])]=0
			dict2[hash(word2[i])]=0
	copie1.sort()
	copie2.sort()
	copie1.reverse()
	copie2.reverse()
	if(len(copie1)==0): return 0
	r=len(copie1)
	for i in range(r):
		del word1[copie1[i]]
		del word2[copie2[i]]
	if(Case==4):
		print(copie1)
		print(copie2)
	return r+calcul(N-r,word1,word2,Case)

# Main
multiprocessed=False # Décide si l'on parallélise les calculs pour gagner du temps
if (multiprocessed): from multiprocessing import Pool
else: output = open('Output.txt','w')
if ((not multiprocessed) or __name__ == '__main__'):
	with open("Input.txt", "r") as input:
		lines=input.readlines()
	T=int(lines[0])
	line=1
	Case=1
	calculs=[]
	while(line<len(lines)):
		N=int(lines[line])
		line=line+1
		word1=['']*N
		word2=['']*N
		for i in range(N):
			word1[i],word2[i]=lines[line].rstrip().split(' ')
			line=line+1
		entrees=[N,word1,word2,Case]
		if (not multiprocessed): output.write('Case #'+str(Case)+': '+executer_calcul(entrees)+'\n')
		else: calculs.append(entrees)
		Case=Case+1
	if (multiprocessed):
		pool=Pool(3) # Décide du nombre de processus à faire tourner en parallèle
		results=pool.map(executer_calcul,calculs)
		output = open('Output.txt','w')
		for case in range(len(results)):
			output.write('Case #'+str(case+1)+': '+results[case]+'\n')
	output.close()

