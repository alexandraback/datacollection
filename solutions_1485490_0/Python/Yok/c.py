'''
Created on May 6, 2011

@author: jirasak
'''

def calculate(Bs, Ts, posB, posT, usedB, usedT):
    numBoxes = 0
    while True:
        if posB * 2 >= len(Bs) or posT * 2 >= len(Ts):
            return numBoxes
        if Bs[(posB * 2) + 1] == Ts[(posT * 2) + 1]:
            use = min(Bs[posB * 2]- usedB, Ts[posT * 2] - usedT)
            numBoxes += use
            if use == Bs[(posB * 2)] - usedB:
                posB += 1
                usedB = 0
                usedT += use
            else:
                posT += 1
                usedT = 0
                usedB += use
        else:
            # dump Toy
            A = calculate(Bs, Ts, posB + 1, posT, 0, usedT)
            # dump Box
            B = calculate(Bs, Ts, posB, posT+1, usedB, 0)
            if A > B:
                return numBoxes + A
            return numBoxes + B
    return numBoxes

def solve(i, Bs, Ts):
    return calculate(Bs, Ts, 0, 0, 0, 0)

if __name__ == '__main__':
    fIn = file('C-small-attempt0.in')
    inLines = fIn.readlines()
    fIn.close()
    
    inLines = inLines[1:]
    numLines = len(inLines)
    i = 0
    numCase = 0
    while i < numLines:
        xLine = [x for x in (inLines[i].strip().split(' '))]
        NB = int(xLine[0])
        NT = int(xLine[1])
        Bs = [int(x) for x in inLines[i + 1].strip().split(' ')]
        Ts = [int(x) for x in inLines[i + 2].strip().split(' ')]
        i += 3
        numCase += 1
#        print lines
        data = solve(i, Bs, Ts)
        print 'Case #%s: %s' % (numCase, data)
    