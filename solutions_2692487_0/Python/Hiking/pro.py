#!/usr/bin/python
import sys
f_input = open(sys.argv[1])

problems = int(f_input.readline().rstrip())

def solve(mine, others):
    ## exception ##
    if(mine==1): return len(others)

    ## init ##
    others.sort()
    ans = 0

    while(others):
        now = others.pop(0)
        tmpadd = 0

        ## add any ##
        #print now, mine
        while(now >= mine):
            #print now, mine
            mine += (mine-1)
            tmpadd += 1
        mine += now

        ## add or not ##
        if( (len(others)+1) > tmpadd):
            ans += tmpadd
        else:
            ans += (len(others)+1)
            break
    return ans

for i in xrange(problems):
    mine = int(f_input.readline().rstrip().split()[0])
    others = map(int, f_input.readline().rstrip().split())
    
    sys.stdout.write("Case #"+str(i+1)+": "+str(solve(mine, others))+"\n")
