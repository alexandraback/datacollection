import numpy as np

infile = open("input.in")
lines = infile.read().split('\n')
numCases = int(lines[0])
lines = lines[1:]
infile.close()

outfile = open('output.out','w')

def trimLosses(naomi,ken):
    losses, naomi2, ken2 = trimNaomiLosses(naomi,ken)
    losses2, naomi3, ken3 = trimKenWins(naomi2,ken2)
    return losses+losses2, naomi3, ken3

def trimNaomiLosses(naomi,ken):
    losses = 0
    for i in range(len(naomi)):
        if (naomi[i] < ken[0]):
            losses += 1
    return losses,naomi[losses:],ken[:len(ken)-losses]

def trimKenWins(naomi,ken):
    losses = 0
    for i in range(len(naomi)):
        if (ken[len(ken)-1-i] > naomi[len(naomi)-1]):
            losses += 1
    return losses, naomi[losses:],ken[:len(ken)-losses]

def trimWins(naomi,ken):
    return trimNaomiWins(naomi,ken)


def trimNaomiWins(naomi,ken):
    wins = 0
    while(len(naomi) > 0 and ken[0] < naomi[0]):
        ken = ken[1:]
        naomi = naomi[1:]
        wins += 1
    return wins,naomi,ken

for i in range(numCases):
    warWins = 0
    deceitWarWins = 0
    data = lines[i*3:i*3+3]
    numBlocks = int(data[0])
    naomi = map(float, data[1].split(' '))
    ken = map(float, data[2].split(' '))
    naomi = np.sort(naomi)
    ken = np.sort(ken)
    
    print naomi
    print ken
    deceitLosses = 0
    for j in range(numBlocks):
        if (naomi[j-warWins] > ken[j]):
            warWins += 1

    while(len(naomi)!=0):
        losses,naomi,ken = trimLosses(naomi,ken)
        wins,naomi,ken = trimWins(naomi,ken)
        deceitWarWins += wins

    outfile.write("Case #" + str(i+1) + ": " + str(deceitWarWins) + " " + str(warWins) + "\n")
    
    print "Case #" + str(i+1) + ": " + str(deceitWarWins) + " " + str(warWins) + "\n"
outfile.close()

