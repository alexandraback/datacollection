def check(start, end):
    alreadySeen = set()
    res = 0
    numDigits = len(str(start))
    for number in range(start,end):
	for shift in range(1,numDigits):
	    leftSide=number/(10**shift)
	    rightSide=number%(10**shift)
	    newNumber=leftSide+rightSide*(10**(numDigits-shift))
	    if newNumber > number and newNumber <= end and (number,newNumber) not in alreadySeen:
		res+=1
		alreadySeen.add((number,newNumber))
    return res


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
        res="Case #"+str(i+1)+": "+str(check(numList[0],numList[1]))+"\n"
	output.write(res)
    output.close()
	
if __name__=='__main__':
    main()

def test(input, out):
    sys.argv=['']
    sys.argv.append(input)
    sys.argv.append(out)
    main()