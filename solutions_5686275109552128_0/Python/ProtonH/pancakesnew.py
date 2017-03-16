import sys

args = sys.argv

if len(args) == 2:
    readLoc = args[1]
    f = open(readLoc,'r')
    of = open('output.txt','w')
    breakFlag = False
    num = 0
    numCalculated = False
    i = -1
    while not breakFlag:
        l = f.readline()
        if not numCalculated:
            num = int(l.strip())
            numCalculated = True
            i = 0
        elif i < num:
            l1 = f.readline()
            d = int(l.strip())
            l1 = l1.strip()
            ndsTemp = l1.split(' ')
            nds = []
            for nT in ndsTemp:
                nds.append(int(nT))
            P = nds
            ans = max (P)

            # Traversing block allocation size, and then optimize the time 
            Z = 2 
            while Z <ans:
                ans = min(ans, sum([(x - 1 ) // Z for x in P]) + Z)
                Z = Z + 1
            of.write('Case #%d: %s\n' % (i + 1 , ans))
            print( 'Case #%d: %s' % (i + 1 , ans))
            i = i+1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()
