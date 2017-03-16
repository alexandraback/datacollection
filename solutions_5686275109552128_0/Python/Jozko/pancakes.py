'''
Created on Apr 11, 2015

@author: jozefmokry
'''
import os, time, numpy

def read(path):
    date = time.strftime('%d_%h_%H_%M_%S')
    print date
    with open(path, 'r') as f:
        T = f.readline().strip()
        T = int(T)
        
        outPath = os.path.splitext(path)[0] + 'OUT.txt'
        out = open(outPath, 'w')
        for i in range(T):
            line = f.readline().strip()
            D = int(line)
            
            plates = f.readline().strip().split(' ')
            plates = map(int, plates)
            assert D == len(plates), (D, len(plates))
            ans = solve(plates)
            out.write('Case #%d: %d\n' % (i+1, ans))
            
        out.flush()
        out.close()
    print time.strftime('%d_%h_%H_%M_%S')
    print 'DONE'
    

def solve(plates):
    bestTime = numpy.inf
    maxPlate = max(plates)
    for i in range(1, maxPlate + 1):
        cost = 0
        for plate in plates:
            #calculate cost if you want to split
            #plate pancakes into piles of i pancakes
            if plate > i:
                cost += plate/i - 1
                if plate % i != 0:
                    cost += 1
        bestTime = min(bestTime, cost + i)
    return bestTime
            
read('B-small-attempt0.in') 