import math
X=open("csm2.in")
z=open("output.txt","w")
dictFile=open("dictionary.txt")
words=dictFile.readlines()
for index in range(0,len(words)):
    words[index]=words[index].rstrip().lstrip()


def binarySearch(string,low,high,dictionary):
    middle=(low+high)/2
    if low>=high:
        return min(low,high)-2
    compareString=dictionary[middle]
    for index in range(0,len(string)):
        if index==len(compareString):
            return binarySearch(string,middle+1,high,dictionary)
        if string[index]>compareString[index]:
            return binarySearch(string,middle+1,high,dictionary)
        elif string[index]<compareString[index]:
            return binarySearch(string,low,middle-1,dictionary)
    return binarySearch(string,low,middle,dictionary)

def validMatch(string1,string2,firstMismatch):
    counter=1
    misMatchCounter=0
    if not (len(string1)==len(string2)):
        return (False,False)
    for index in xrange(0,len(string1)):
        counter-=1
        if not string1[index]==string2[index]:
            if index<firstMismatch:
                return (-10,False)
            if counter>0:
                return (False,False)
            misMatchCounter+=1
            counter=5
    return (misMatchCounter+1,max([counter-1,0]))


def recSolveCase(nextString,dictionary,firstMismatch,missSoFar,known):
    global bestAnswer
    curKey=nextString+":"+str(firstMismatch)
    if known.has_key(curKey):
        return known[curKey]
    if missSoFar>=bestAnswer:
        return bestAnswer+1
    if len(nextString)==0:
        return 0
    startIndex=0
    answer=100000000000000
    if known.has_key(nextString):
        goodStrings=known[nextString]
        
        for item in goodStrings:
            if not validMatch(nextString,item[0],firstMismatch):
                continue
            nextAnswer=item[1]+recSolveCase(nextString[len(item[0]):],dictionary,item[2],missSoFar+item[1],known)
            if nextAnswer<answer:
                answer=nextAnswer
    goodStrings=[]
    seen={}
    for index in range(startIndex,len(dictionary)):
        testString=dictionary[index]
        nextMismatches,nextFirst=validMatch(testString,nextString[0:len(testString)],firstMismatch)
        if nextMismatches<0:
            break
        if nextMismatches:
            seenKey=str(nextMismatches)+":"+str(len(testString))
            if seen.has_key(seenKey):
                continue
            else:
                seen[seenKey]=0
            goodStrings.append((testString,nextMismatches,nextFirst))
            nextMismatches-=1
            nextAnswer=nextMismatches+recSolveCase(nextString[len(testString):],dictionary,nextFirst,missSoFar+nextMismatches,known)
            if nextAnswer<answer:
                bestAnswer=min(bestAnswer,answer)
                answer=nextAnswer
    known[curKey]=answer
    if firstMismatch==0:
        known[nextString]=goodStrings
    return answer
            

def solveCase(nextString,dictionary):
    return str(recSolveCase(nextString,dictionary,0,0,{}))

case=0
cases=int(X.readline())
while case<cases:
    case+=1
    print case
    nextString=X.readline().rstrip().lstrip()
    bestAnswer=len(nextString)+1
    z.write("Case #"+str(case)+": "+solveCase(nextString,words)+"\n")
z.close()
