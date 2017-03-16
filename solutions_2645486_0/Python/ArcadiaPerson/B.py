import math


def findEnergyToUse(energy,maxEnergy,regain):
    lostEnergy=maxEnergy-energy
    if regain<=lostEnergy:
        return 0
    
    return min([energy,regain-lostEnergy])

def solveCase(energy,maxEnergy,regain,actList,curIndex,known):
    if energy>maxEnergy:
        energy=maxEnergy
    if curIndex==len(actList)-1:
        return energy*actList[-1]
    curKey=str(energy)+":"+str(curIndex)
    
    if known.has_key(curKey):
        return known[curKey]
    answer=0
    if actList[curIndex]<=actList[curIndex+1]:
        energyToUse=findEnergyToUse(energy,maxEnergy,regain)
        if energyToUse>=0:
            energy=energy-energyToUse
            answer=energyToUse*actList[curIndex]
            answer=answer+solveCase(energy+regain,maxEnergy,regain,actList,curIndex+1,known)
        else:
            answer=solveCase(min([maxEnergy,energy+regain]),maxEnergy,regain,actList,curIndex+1,known)
    else:
        for possible in range(0,energy+1):
            current=(possible*actList[curIndex])+solveCase(energy-possible+regain,maxEnergy,regain,actList,curIndex+1,known)
            if current>answer:
                answer=current
    

    known[curKey]=answer
    return answer
    

X=open("bsmr.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())
while case<cases:
    case+=1
    print case
    currentline=X.readline().rstrip().lstrip().split()
    energy=int(currentline[0])
    regain=int(currentline[1])
    known={}
    actList=X.readline().rstrip().lstrip().split()
    for index in range(0,len(actList)):
        actList[index]=int(actList[index])
    z.write("Case #"+str(case)+": "+str(solveCase(energy,energy,regain,actList,0,known))+"\n")
z.close()
