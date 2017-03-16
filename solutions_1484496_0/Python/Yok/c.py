'''
Created on May 6, 2011

@author: jirasak
'''

def solve(i, line):
    import itertools
    bigList = []
    bigMap = {}
    for i in range(1, 20):
        p = itertools.combinations(line, i)
        while True:
            try:
                value = p.next()
                bigList.append(value)
                theSum = sum(value)
                if bigMap.has_key(theSum):
                    return bigMap[theSum], value
                bigMap[theSum] = value
            except:
                break
#    for p in range(len(bigList)):
#        for q in range(p+1, len(bigList)):
#            if sum(bigList[p]) == sum(bigList[q]):
#                return bigList[p], bigList[q]
    return 'Impossible'

if __name__ == '__main__':
    fIn = file('C-small-attempt1.in')
    inLines = fIn.readlines()
    fIn.close()
    
    inLines = inLines[1:]
    numLines = len(inLines)
    i = 0
    while i < numLines:
        line = [int(x) for x in inLines[i].strip().split(' ')][1:]
        i += 1
        data = solve(i, line)
        if data == 'Impossible':
            print 'Case #%s: Impossible' % i
        else:
            print 'Case #%s:' % i
            print ' '.join(['%s' % x for x in data[0]])
            print ' '.join(['%s' % x for x in data[1]])
    