from pprint import pprint as pp 
from collections import defaultdict

def genPossibleScores(scoreTemplate):
    if scoreTemplate[0] == "?":
        possibleChars = [str(n) for n in range(10)]
    else:
        possibleChars = [scoreTemplate[0]]
    if len(scoreTemplate) == 1:
        return possibleChars
    possibleNext = genPossibleScores(scoreTemplate[1:])
    possibleStrings = []
    for ch in possibleChars:
        for nxt in possibleNext:
            possibleStrings.append(ch+nxt)
    return possibleStrings

def findBest(possibleScoreAs, possibleScoreBs):
    smallest_diff = 10**max(len(scoreA),len(scoreB))
    bestA = None
    bestB = None
    
    for psa in possibleScoreAs:
        #psa = int(psa_str,base=10)
        for psb in possibleScoreBs:
            #psb = int(psb_str,base=10)
            diff = abs(psb-psa)
            if diff < smallest_diff:
                smallest_diff = diff
                bestA = psa
                bestB = psb
                if diff == 0:
                    return bestA,bestB
    return bestA,bestB


num_cases = int(raw_input())  # read a line with a single integer
    
for casenum in xrange(num_cases):
    scores = raw_input()
    ###
    scoreA,scoreB = scores.split(" ")
    
    possibleScoreAs = [int(sc,10) for sc in genPossibleScores(scoreA)]
    possibleScoreBs = [int(sc,10) for sc in genPossibleScores(scoreB)]
            
    bestA,bestB = findBest(possibleScoreAs, possibleScoreBs)
    ###
    bestAstr = "{score:0{length}}".format(score=bestA, length=len(scoreA))
    bestBstr = "{score:0{length}}".format(score=bestB, length=len(scoreB))
    print "Case #{}: {} {}".format(casenum+1, bestAstr, bestBstr)
