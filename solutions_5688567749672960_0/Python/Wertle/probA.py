# CodeJam 2015 Problem A
# Nicholas Sharp - nsharp33@gmail.com

import fileinput

nCases = int(raw_input())

for iCase in range(nCases):

    N = int(raw_input())
    #print("N = " + str(N))

    reached = set()
    toAdd = set()
    toAdd.add(1)

    nUsed = 0
    found = False

    while(not found):

        #print("Reached = " + str(reached))
        #print("toAdd = " + str(toAdd))

        newToAdd = set()

        for x in toAdd:

            if(x == N):
                found = True
                break


            t1 = x+1
            t2 = int(str(x)[::-1])

            if(t1 not in reached):
                reached.add(t1)
                newToAdd.add(t1)
                
            if(t2 not in reached):
                reached.add(t2)
                newToAdd.add(t2)

        toAdd = newToAdd
        nUsed += 1

    print("Case #%d: %d"%(iCase+1, nUsed))
