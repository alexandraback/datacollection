#import re #regex
#import math #math
# math.sqrt(x) -> squre root of x
# math.pow(x, y) -> x ^ y
# math.ceil(math.sqrt(a))

#deceit -> she will only lose the ones she could never win in spite of what he picked
#war -> 
inFile = "D-large"
def main():
    f = open("C:\Users\Peter\Downloads\\" + inFile + ".in", "r")    
    o = open("C:\Users\Peter\Desktop\\" +inFile + ".out", "w")
    
    
    n = int(f.readline())

    for x in range(n):
        numBlocks = int(f.readline()[:-1])
        output(x+1, process(numBlocks, f.readline()[:-1], f.readline()[:-1]), o)

def process(numBlocks, nLine, kLine):
    naomiBlocks = [float(x) for x in nLine.split(" ")]
    kenBlocks = [float(x) for x in kLine.split(" ")]
    if len(naomiBlocks) != numBlocks or len(kenBlocks) != numBlocks:
        print "problem"
    naomiBlocks.sort()
    kenBlocks.sort()
    d = deceitfulWar([x for x in naomiBlocks], [y for y in kenBlocks])
    w = war([x for x in naomiBlocks], [y for y in kenBlocks])
    return str(d) + " " + str(w)

def deceitfulWar(naomi, ken):
    #return wins from naomi
    #assume they're sorted and ok to modify array
    wins = 0
    while len(naomi) > 0:
        if naomi[0] > ken[0]:
            #naomi legitimately wins by forcing his lowest block to lose to her lowest
            wins = wins + 1
            naomi = naomi[1:]
            ken = ken[1:]
        elif ken[0] > naomi[0]:
            #naomi must lose but can force ken to lose his highest block
            naomi = naomi[1:]
            ken = ken[:-1]
        else :
            print "problem, tie"
    return wins

def war(naomi, ken):
    #return wins from naomi
    #assume they're sorted and ok to modify array
    wins = 0
    while len(naomi) > 0:
        if ken[0] > naomi[0]:
            naomi = naomi[1:]
            ken = ken[1:]
        elif naomi[0] > ken[0]:
            #ken will use his losing blocks to take out naomi's highest
            #but they still count as a win for naomi
            wins = wins + 1
            naomi = naomi[:-1]
            ken = ken[1:]
        else: 
            print "problem, tie"
    return wins

def output(case, outline, o):
    print "Case #" + str(case) + ": " + str(outline)
    o.write( "Case #" + str(case) + ": " + str(outline) + "\n")
    
if __name__ == "__main__":
    main()