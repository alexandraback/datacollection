from collections import*

f=open("C-small-attempt1.in",'r')
g=open("OUT.txt",'w')

T=int(f.readline())
for i in range(1,T+1):
	ans=0
	[C,D,V]=[int(i) for i in f.readline().split()]
	coins=[int(i) for i in f.readline().split()]
	
	# C=1
	reached=set([0])
	for coin in coins:
		news=set()
		for summ in reached:
			if summ+coin<=V:
				news.add(summ+coin)
		reached=reached.union(news)
	#print(C,D,V,coins)
	#print(reached)
	
	ans=0
	for val in range(V+1):
		if val not in reached:
			ans+=1
			news=set()
			for summ in reached:
				if summ+val<=V:
					news.add(summ+val)
			reached=reached.union(news)
	
	#print(reached)
	
	g.write("Case #{}: {}\n".format(i,ans))

f.close()
g.close()
