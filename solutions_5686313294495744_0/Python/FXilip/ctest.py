with open("C-small-attempt1.in") as f:
#with open("C-large.in") as f:
#with open("test.in") as f:
	dat = f.read().splitlines()
	
import random
	
def rem(i,topics,counts):
	t = topics[i]
	del topics[i]
	del counts[i]
			
	for j in range(topics.__len__()):
		if topics[j][0] == t[0]:
			counts[j][0] = 0
		if topics[j][1] == t[1]:
			counts[j][1] = 0
	return topics,counts
	
def remfree(topics,counts,fake):
	for i in range(topics.__len__()-1,-1,-1):
		if counts[i][0] == 0 and counts[i][1] == 0:
			del topics[i]
			del counts[i]
			fake += 1
	return topics,counts,fake
	
def remalone(topics,counts,fake):
	#su jedinecne, killnem
	for i in range(topics.__len__()-1,-1,-1):
		if counts[i][0] == 1 or counts[i][1] == 1:
			#print("kill "+str(topics[i]))
			topics,counts = rem(i,topics,counts)
	
	#print(topics)
	#print(counts)
	#su volne, su to fejky
	topics,counts,fake = remfree(topics,counts,fake)	

	return topics,counts,fake
	
def break_cycle(topics,counts):
	poss = []
	for i in range(topics.__len__()-1,-1,-1):
		if counts[i][0] > 1 and counts[i][1] > 1:
			#print("kill2 "+str(topics[i]))
			poss.append(i)
	if poss.__len__()!=0:
		i = random.randint(0,poss.__len__()-1)
		i = poss[i]
		#print(i)
		return rem(i,topics,counts)
			
	i = random.randint(0,topics.__len__()-1)
	#print("kill0 "+str(topics[i]))
	return rem(0,topics,counts)
	
nn = int(dat[0])
out = []
casei = 1
for case in range(nn):
	n = int(dat[casei])
	topicst = []
	counts = []
	for ii in range(n):
		casei += 1
		topicst.append(dat[casei].split())
	
	ress = []
	for test in range(1000):
		topics = [t for t in topicst]
		t0 = [t[0] for t in topics]
		t1 = [t[1] for t in topics]
		
		for t in topics:
			n0 = t0.count(t[0])
			n1 = t1.count(t[1])
			counts.append([n0,n1])
		
		fake = 0
		topics,counts,fake = remalone(topics,counts,fake)
			
		if topics.__len__() != 0:
			while True:
				topics,counts = break_cycle(topics,counts)
				topics,counts,fake = remfree(topics,counts,fake)	
				if topics.__len__() == 0:
					break
		
		res = "Case #"+str(case+1)+": "+str(fake)
		#print(res)
		ress.append(res)
	#print("\n".join(ress))
	#assert set(ress).__len__() == 1
	print(case+1)
	out.append(max(ress))
	casei += 1

assert out.__len__() == nn
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



