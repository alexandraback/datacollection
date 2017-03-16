file = open("in.in",'r')
file2 = open("out.out","w")
n=int(file.readline())
pp=[]

for i in range(n):
	k=int(file.readline())
	dic={}
	dic2={}
	dic3={}
	pp=[]
	for j in range(k):
		s=file.readline().split()
		for k in range(int(s[0])):
			if dic.has_key(j+1):
				dic[j+1].append(int(s[k+1]))
			else:
				dic[j+1]=[int(s[k+1])]
		if not int(s[0]):
			dic[j+1]=[]
			pp.append(j+1)

	b=True
	b2=True


	while b and b2:
		b=False
		pp2=pp[:]
		pp=[]
		for item in dic.keys():
			for it in pp2:
				if it in dic[item]:
					b=True
					pp.append(item)
					if dic2.has_key(it):
						if item in dic2[it]:
							b2=False
							break
						dic2[it].append([item,0])
					else:
						dic2[it]=[[item,0]]
		break

	b=True
	b2=True
	while b and b2:
		b=False
		for ke in dic2.keys():
			for j in range(len(dic2[ke])):
	
				if dic2[ke][j][1]==0:
					for it in dic.keys():
						if dic2[ke][j][0] in dic[it]:

							if [it,0] in dic2[ke] or [it,1] in dic2[ke]:
								b2=False
								break
							else:
								dic2[ke].append([it,0])
								b=True
					dic2[ke][j][1]=1





	if b2:
		file2.write("Case #"+str(i+1)+": No\n" )
	else:
		file2.write("Case #"+str(i+1)+": Yes\n" )



	
				





	#file2.write(' '.join(ret)+"\n")
file2.close()

