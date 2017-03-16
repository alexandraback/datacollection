'''
Created on May 5, 2012

@author: Chief
'''

if __name__ == '__main__':
    pass


def minVotes(path):
    inputFile = file(path, "r");
    nLines = inputFile.readline();
    allScores = inputFile.readlines();
    inputFile.close();
    newPath=path[:path.find(".")+1]+"out";
    outputFile=file(newPath,"w");
    
    k=1;
    for scores in allScores:
        scores=scores.split()
        nPlayers=int(scores[0])
        scores=map(float,scores[1:])
        totalScore=sum(scores)
        scoresCopy=list(scores)
        bestTie=findBestTie(scoresCopy,totalScore)
        outString="Case #"+str(k)+": "
        for score in scores:
            votes=(100*(bestTie-score)/totalScore)
            if votes>0:
                outString+=str(votes)+" "
            else:
                outString+="0 "
        outString=outString[0:-1]+"\n";
        outputFile.write(outString);
        k+=1;
    outputFile.close();
    
def findBestTie(scores,totalScore):
    scores.sort()
    bestTie=0;
    gotLast=True
    for i in range(len(scores)-1):
        nextHop=(i+1)*(scores[i+1]-scores[i])
        if nextHop<totalScore:
            totalScore-=nextHop
            bestTie=scores[i+1]
        else:
            gotLast=False
            break;
    if gotLast:
        bestTie+=totalScore/(i+2)
    else:
        bestTie+=totalScore/(i+1)
    return bestTie
    
    
#path="D:\\My Documents\\CodeJam\\2012\\Round 1B\\Round 1B\\sample.in"
#path="D:\\My Documents\\CodeJam\\2012\\Round 1B\\Round 1B\\A-small-attempt0.in"
path="D:\\My Documents\\CodeJam\\2012\\Round 1B\\Round 1B\\A-small-attempt1.in"
minVotes(path);