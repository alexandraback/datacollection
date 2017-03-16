import sys
from collections import deque
import heapq
from operator import itemgetter

if __name__ == "__main__":
    f = open( "B-small-attempt0.in" )
    g = open( "output_small.txt","w" )
    #g = sys.stdout

    numcases = f.readline()

    caseI = 1
    line = f.readline()
    while line != "":
        numlevels = int(line)
        target = numlevels * 2
        minstars = [None]*numlevels
        index = 0
        for x in xrange(numlevels):
            i,j = [int(y) for y in f.readline().split()]
            minstars[index] = (i,j)
            index += 1

        minstars.sort()
        #ms = sorted( minstars, key=itemgetter(1,0) )

        s = 0
        h = list(minstars)
        heapq.heapify(h)

        output = ""
        popped = deque()
        nums = 0
        while len(h) > 0:
            #print s,nums,h
            if h[0][-1] <= s:
                x = heapq.heappop(h)
                s += len(x)
                nums += 1
            elif h[0][0] <= s:
                popped.append( heapq.heappop(h) )

            if len(h) == 0 or h[0][0] > s:
                if s == numlevels * 2:
                    output = nums
                    break
                elif len(popped) == 0:
                    output = "Too Bad"
                    break
                else:
                    i,j = popped.pop()
                    heapq.heappush(h,(j,2002))
                    s += 1
                    nums += 1
                    while len(popped) > 0:
                        x = popped.pop()
                        if x[-1] <= s:
                            s += len(x)
                            nums += 1
                        else:
                            heapq.heappush(h,x)
                            

        g.write( "Case #%s: %s\n"%(caseI,output) )
        caseI += 1
        line = f.readline()
    f.close()
    g.close()
