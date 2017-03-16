import math

f = open('B-large.in')
fout = open('B-large.out',mode = 'w')
numtests = int(f.readline())
for x in range(1,numtests+1):
    currbest = 263895682493875634
    f.readline() # IGNORED LOL
    inp = list(map(int,f.readline().split(' '))) #Not ignored :(
    mval = max(inp)
    for bashyval in range(1,mval+1):
        curr = 0
        for val in inp:
            curr += math.ceil(val/bashyval)-1
        currbest = min(currbest,curr+bashyval)
    fout.write("Case #"+str(x)+": "+str(currbest)+"\n")
f.close()
fout.close()
    
