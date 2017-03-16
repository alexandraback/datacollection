def kingdomRush(levels):
    
    stars=0
    levelsPlayed=0
    while True:
        notSecondStar=True
        foundLevel=False
        hardestLevel2=-1
        for each in levels:
            if each[1]!="no":
                notSecondStar=False
                if each[1]<=stars:
                    each[1]="no"
                    if each[0]=="no":
                        stars+=1
                    else:
                        each[0]="no"
                        stars+=2
                    levelsPlayed+=1
                    foundLevel=True
                    break
            if each[0]!="no" and each[0]<=stars:
                assert each[1]!="no"
                if each[1]>hardestLevel2:
                    hardestLevel2=each[1]
                    foundLevel=each
        if notSecondStar:
            return str(levelsPlayed)
        if not foundLevel:
            return "Too Bad"
        if type(foundLevel)==list:
            foundLevel[0]="no"
            stars=stars+1
            levelsPlayed+=1
            

import math
X=open("bsm3.in")
z=open("output.txt","w")
case=0
currentline=X.readline()
currentline=X.readline()
while currentline:
    case+=1
    print case
    levels=int(currentline)
    curLevels=[]
    while levels:
        levels-=1
        curLevels.append(map(int,X.readline().rstrip().lstrip().split()))
    z.write("Case #"+str(case)+": "+kingdomRush(curLevels)+"\n")
    currentline=X.readline()
z.close()
