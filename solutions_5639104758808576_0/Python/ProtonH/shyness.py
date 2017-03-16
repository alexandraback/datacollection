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
            l = l.strip()
            ls = l.split(' ')
            maxShyness = int(ls[0])
            shystring = ls[1]
            totalStanding = 0
            invitation = 0
            for j in range(0,len(shystring)):
                if totalStanding >= j:
                    totalStanding = totalStanding + int(shystring[j])
                else:
                    invitTemp = (j - totalStanding)
                    invitation = invitation + invitTemp
                    totalStanding = totalStanding + invitTemp + int(shystring[j])

            of.write('Case #'+str(i+1)+': '+str(invitation)+'\n')
            print('Case #'+str(i+1)+': '+str(invitation))
            i = i + 1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()
                
