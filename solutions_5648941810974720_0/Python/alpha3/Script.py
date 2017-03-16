
def executer_calcul(entrees):
	S=entrees[0]
	Case=entrees[1]
	occurences=[0]*26
	for i in range(len(S)):
		occurences[ord(S[i])-65]=occurences[ord(S[i])-65]+1
	digits=[]
	n=occurences[25]
	for i in range(n):
		digits.append(0)
		occurences[25]=occurences[25]-1
		occurences[4]=occurences[4]-1
		occurences[14]=occurences[14]-1
	n=occurences[23]
	for i in range(n):
		digits.append(6)
		occurences[23]=occurences[23]-1
	n=occurences[6]
	for i in range(n):
		digits.append(8)
		occurences[6]=occurences[6]-1
		occurences[4]=occurences[4]-1
		occurences[7]=occurences[7]-1
	n=occurences[22]
	for i in range(n):
		digits.append(2)
		occurences[22]=occurences[22]-1
		occurences[14]=occurences[14]-1
	n=occurences[20]
	for i in range(n):
		digits.append(4)
		occurences[20]=occurences[20]-1
		occurences[5]=occurences[5]-1
		occurences[14]=occurences[14]-1
	n=occurences[5]
	for i in range(n):
		digits.append(5)
		occurences[5]=occurences[5]-1
		occurences[21]=occurences[21]-1
		occurences[4]=occurences[4]-1
	n=occurences[7]
	for i in range(n):
		digits.append(3)
		occurences[7]=occurences[7]-1
		occurences[4]=occurences[4]-2
	n=occurences[14]
	for i in range(n):
		digits.append(1)
		occurences[14]=occurences[14]-1
		occurences[4]=occurences[4]-1
	n=occurences[21]
	for i in range(n):
		digits.append(7)
		occurences[21]=occurences[21]-1
		occurences[4]=occurences[4]-2
	n=occurences[4]
	for i in range(n):
		digits.append(9)
		occurences[4]=occurences[4]-1
	digits.sort()
	result=''
	for i in range(len(digits)):
		result=result+str(digits[i])
	return result


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
		S=lines[line].rstrip()
		line=line+1
		entrees=[S,Case]
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

