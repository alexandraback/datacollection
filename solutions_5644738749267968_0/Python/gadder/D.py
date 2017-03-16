import operator
def getMaxScore(NList, KList):
	#print NList
	#print KList
	maxScore=sum(map(operator.gt,NList,KList))
	return maxScore

def main():
	T=input()
	for j in range(T):
		n=input()
		s=raw_input();
		naomi=map(float, s.strip().split(' '))
		naomi=sorted(naomi)
		NList=list(naomi)
		s=raw_input();
		ken=map(float, s.strip().split(' '))
		ken=sorted(ken)
		KList=list(ken)
		count=0
		for i in range(n):
			try:
				naomi_chosen=naomi[0]
				naomi.remove(naomi_chosen)
				try:
					ken_chosen=min(x for x in ken if x > naomi_chosen)
					ken.remove(ken_chosen)
				except ValueError:
					count=count+1
			except ValueError:
				pass
		maxScore=0
		while maxScore<len(NList):
			maxScore=getMaxScore(NList,KList)
			if NList[0]<KList[len(KList)-1]:
				NList.remove(NList[0])
				KList.remove(KList[len(KList)-1])
		print 'Case #'+str(j+1)+': '+str(maxScore)+' '+str(count)
		
if __name__ == "__main__": 
	main()
