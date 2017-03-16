import math
X=open("csm4.in")


def factorProduct(totalNums,minimum,maximum,product):
    if product==1:
        return [[]]
    if totalNums==0:
        return None
    possible=[]
    if product>=2 and product<=maximum and product>=minimum:
        possible.append([product])
    for number in range(minimum,maximum+1):
        if number>=(product/2)+1:
            break
        numberCounter=0
        while True:
            numberCounter+=1
            if numberCounter>totalNums:
                break
            if not (product%(number**numberCounter))==0:
                break
            nextPossible=factorProduct(totalNums-numberCounter,number+1,maximum,product/(number**numberCounter))
            if  not nextPossible==None:
                for each in nextPossible:
                    for times in range(0,numberCounter):
                        each.append(number)
            
                possible.extend(nextPossible)
    return possible
        

def solveCase(totalNums,maximum,products):
    answer=[]
    usefulFactors=[]
    while True:
        foundItem=False
        for item in products:
            if item==1:
                continue
            maxDict={}
            minDict={}
            for number in range(2,maximum+1):
                minDict[number]=100000000000000000000000000000
            factors=factorProduct(totalNums-len(answer),2,maximum,item)
            usefulFactors.append(factors)
            #print factors, totalNums-len(answer),2,maximum,item
            if factors==None or len(factors)==0:
                continue
            for nextFactor in factors:
                for newNumber in range(2,maximum+1):
                    minDict[newNumber]=min([minDict[newNumber],nextFactor.count(newNumber)])
        
            for newNumber in range(2,maximum+1):
                
                while True:
                    if answer.count(newNumber)<minDict[newNumber]:
                        
                        answer.append(newNumber)
                        foundItem=True
                    else:
                        break
        if not foundItem:
            break
    if not len(answer)==totalNums:
        for first in usefulFactors:
            for item in first:
                for number in range(2,maximum+1):
                    if not number in answer and number in item:
                        answer.append(number)
                        if len(answer)==totalNums:
                            for each in range(0,len(answer)):
                                
                                answer[each]=str(answer[each])
                            return "".join(answer)
        
    while len(answer)<totalNums:
        
        answer.append(2)
    for each in range(0,len(answer)):
        answer[each]=str(answer[each])
    return "".join(answer)
    

z=open("output.txt","w")
case=0
cases=int(X.readline())
while case<cases:
    case+=1
    print case
    c=X.readline().rstrip().lstrip().split()
    R=int(c[0])
    N=int(c[1])
    M=int(c[2])
    K=int(c[3])
    answers=[]
    while R:
        R-=1
        print R
        products=X.readline().rstrip().lstrip().split()
        for index in range(0,len(products)):
            products[index]=int(products[index])
        answers.append(solveCase(N,M,products))
    
    z.write("Case #1:\n")
    for item in range(0,len(answers)-1):
        z.write(str(answers[item])+"\n")
    z.write(str(answers[-1]))
z.close()
