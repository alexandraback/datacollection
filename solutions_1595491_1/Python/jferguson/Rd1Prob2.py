def check(scoreList, goodScore, numSurprises):
    numGood=0
    for score in scoreList:
  	if score > 30 or score < goodScore:
	    continue
	else:
	    newScore=score-goodScore
	    if newScore/2 < goodScore-2:
		continue #That person cannot get goodScore
	    elif newScore/2 == goodScore-2 and numSurprises==0:
		continue
	    elif newScore/2 == goodScore-2 and numSurprises>0:
		numSurprises-=1
		numGood+=1
	    else:
		numGood+=1
    return numGood

import sys
def main():
    input = open(sys.argv[1])
    output = open(sys.argv[2],'w')
    caseString=input.readline()
    if caseString[-1:]=='\n':
	caseString=caseString[:-1]
    numCases=int(caseString)
    for i in range(numCases):
	current=input.readline()
	if current[-1:]=='\n':
	    current=current[:-1]
	numList = current.strip().split(' ')
	for j in range(len(numList)):
	    numList[j]=int(numList[j])
        res="Case #"+str(i+1)+": "+str(check(numList[3:],numList[2],numList[1]))+"\n"
	output.write(res)
    output.close()
	
if __name__=='__main__':
    main()

def test(input, out):
    sys.argv=['']
    sys.argv.append(input)
    sys.argv.append(out)
    main()