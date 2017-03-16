'''
Created on Apr 26, 2013

@author: Matt Dodge
'''

inFile = open('A-small-attempt0.in','r+')
outFile = open('A-small0.out','w')
#outFile = 'stdout'

def output(st):
    if outFile == 'stdout':
        print st
    else:
        outFile.write(st)

# paint required for n rings starting at radius r
def paintReqd(n, r):
    return 2*n*n + (2*r-1) * n


def bisect(n, lowN, highN, t, r, maxN):
    vol = paintReqd(n, r)
#    print 'Checking {0} and volume is {1}'.format(n, vol)
    
    if n <= lowN or n >= highN or lowN >= highN:
        return maxN
    
    if vol > t:
        # we are using too much, go less
        return bisect(int((n-lowN)/2) + lowN, lowN, n, t, r, maxN)
    elif vol < t:
        # we aren't using enough, try for more!
        return bisect(int((highN-n)/2) + n, n, highN, t, r, max(n,maxN))
    else:
        return max(n,maxN)
         


if __name__ == '__main__':
    numCases = int(inFile.readline().rstrip('\n'))
    
    
    
    for case in range(1, numCases+1):
        [r,t] = [int(x) for x in inFile.readline().rstrip('\n').split(' ')]

#        output('Case #{0}: {1}\n'.format(case, bisect(10,20,t,r,0)))
        output('Case #{0}: {1}\n'.format(case, bisect(707106780,0,1414213560,t,r,0)))
    
