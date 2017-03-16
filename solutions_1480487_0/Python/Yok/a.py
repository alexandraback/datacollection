'''
Created on May 6, 2011

@author: jirasak
'''

def solve(i, line):
    total = sum(line)
    newTotal = total * 2
    target = newTotal / len(line)
    
    newList = []
    for k in line:
        if k <= target:
            newList.append(k)
    total2 = sum(newList) + total
    newTarget = float(total2) / len(newList)
        
    y = [(float(newTarget - j) / total) * 100.0 if j in newList else 0.0 for j in line]
    z = ['%.6f' % j for j in y] 
    return ' '.join(z)

if __name__ == '__main__':
    fIn = file('A-small-attempt1.in')
    inLines = fIn.readlines()
    fIn.close()
    
    inLines = inLines[1:]
    numLines = len(inLines)
    i = 0
    while i < numLines:
        line = [int(x) for x in inLines[i].strip().split(' ')][1:]
        i += 1
        data = solve(i, line)
        print 'Case #%s: %s' % (i, data)
    