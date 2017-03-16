
def process(line):

	word=""
	for i in range(len(line)):
		letter=line[i]

		if len(word)==0:
			word=letter
			continue

		leftMost=word[0]

		if letter>=leftMost:
			word=letter+word
		else:
			word=word+letter
		
	return word



def main():
	with open("A-small-attempt0.in", "r") as ins:
		numOfTestCases=int(ins.readline())
		#print "#cases "+str(numOfTestCases)
		

		cases=[]
		for i in range(numOfTestCases):
			line=ins.readline().rstrip()
			
			# Case #1: 2 3
			print "Case #"+str(i+1)+": "+process(line)
			




main()