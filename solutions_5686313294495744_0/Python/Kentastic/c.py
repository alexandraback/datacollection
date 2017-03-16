import sys
from random import shuffle

def FindFakes(topicNum, topics, firstWords, secondWords):
    fakes = 0
    for i in range(0,topicNum):
        words = topics[i].split(' ')
        if i == topicNum:
            if words[0] in (firstWords[:i]):
                if words[1] in (secondWords[:i]):
                    fakes += 1
                    firstWords[i] = words[0]+str(i)
                    secondWords[i] = words[1]+str(i)
        else:
            if words[0] in (firstWords[:i]+firstWords[i+1:]):
                if words[1] in (secondWords[:i]+secondWords[i+1:]):
                    fakes += 1
                    firstWords[i] = words[0]+str(i)
                    secondWords[i] = words[1]+str(i)
    return fakes

inputStrings = open('C-small-attempt0.in', 'r').read().splitlines()
caseNum = int(inputStrings[0])
outString = ""

lineNum = 1;
for case in range(1,caseNum+1):
    topics = []
    firstWords = []
    secondWords = []

    topicNum = int(inputStrings[lineNum])
    lineNum += 1

    for i in range(0,topicNum):
        topic = inputStrings[lineNum]
        lineNum += 1
        topics.append(topic)
        words = topic.split(' ')
        firstWords.append(words[0])
        secondWords.append(words[1])

    fakeNum = 0

    for i in range(0, 64):
        randTopics = []
        randFirstWords = []
        randSecondWords = []
        index_shuf = list(range(len(topics)))
        shuffle(index_shuf)
        for i in index_shuf:
            randTopics.append(topics[i])
            randFirstWords.append(firstWords[i])
            randSecondWords.append(secondWords[i])
        fakeNum = max(FindFakes(topicNum, randTopics, randFirstWords, randSecondWords), fakeNum)

    outString += "Case #" + str(case) + ": " + str(fakeNum) + '\n'

fileOut = open('C-small-attempt0.out', 'w')
fileOut.write(outString)
fileOut.close()