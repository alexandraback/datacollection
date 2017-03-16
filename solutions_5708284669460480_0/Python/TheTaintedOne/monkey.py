import sys
import itertools
from collections import defaultdict

lines = sys.stdin.readlines()

ntests = int(lines[0])


def getWordProb(wordProbs, target):
    p = 1.0
    for c in target:
        p *= wordProbs[c]
    return p


curr = 1
for t in range(1, ntests+1):
    # print "\n"
    K, L, S = [int(x) for x in lines[curr].split()]
    # print K,L,S
    keyboard = lines[curr+1].strip()
    target = lines[curr+2].strip()
    # print keyboard, target

    wordCounts = defaultdict(float)
    for c in keyboard:
        wordCounts[c] += 1
    wordProbs = defaultdict(float)
    for k,v in wordCounts.items():
        wordProbs[k] = v/len(keyboard)
    # print wordProbs

    headLen = 0
    for i in range(1, len(target)):
        if target[i:]==target[:-i]:
            headLen = i
            break

    if headLen>0:
        headWord = target[:headLen]
        tailWord = target[headLen:]
        tailLen = len(target)-headLen
        maxCount = (S-tailLen)/headLen
    else:
        headWord = target
        tailWord = ""
        maxCount = S/len(target)

    if not set(target).issubset(set(keyboard)):
        maxCount = 0
    headProb = getWordProb(wordProbs, headWord)
    tailProb = getWordProb(wordProbs, tailWord)
    expectedCount = headProb*max([0, maxCount-1]) + headProb*tailProb
    # print maxCount, expectedCount
    # print headProb, tailProb

    curr += 3
    print "Case #"+ str(t) + ": %0.6f" % (maxCount-expectedCount)
