#!/usr/bin/python3.2
#name = 'C.test'
name = 'C-small-1-attempt2.in'
#name = 'C-large.in'

def make():
    R,N,M,K = [int(i) for i in FILE.readline().split(' ')]

    events = []
    for i in range(0,R):
        events.append([int(i) for i in FILE.readline().split(' ')])

    for choice in events:
        potentials = {i:0 for i in range(2,M+1) }
        for p in potentials:
            for c in choice:
                if c % p == 0: potentials[p] += 1
        outList = [(potentials[i],i) for i in potentials if potentials[i] > 0]

        i = 1
        outStr = ""
        for el in outList:
            if i <= N:
                outStr = outStr + str(el[1])
        if len(outList) > 0:
            while len(outStr) < N:
                outStr = outStr + str(outList[0][1])
        else:
            while len(outStr) < N:
                outStr = outStr + '2'
        print(outStr)
















FILE = open(name)
T = int(FILE.readline())

for i in range(1, T+1):
    print("Case #" + str(i) + ":")
    make()