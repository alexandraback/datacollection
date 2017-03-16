FILE = "P1_small_3"
try:
    inFile = open(FILE+".txt")
except:
    pass

def read():
    try:
        return inFile.readline().strip()
    except:
        return raw_input().strip()

    
def check(cur,motes):
    moves = 0
    for m in motes:
        if m < cur:
            cur += m
        else:
            while m >= cur:
                cur += cur-1
                moves += 1
            cur += m
    return moves

    
out = open("P1.out","w")
cases = int(read())
for case in xrange(cases):
    a,n = map(int,read().split())
    motes = map(int,read().split())
    motes.sort()
    
    if a == 1:
        best = n
    
    else:
        best = n
        for i in range(n):
            moves = check(a,motes[:i+1])+n-i-1
            #print i,moves
            best = min(best,moves)
    out.write("Case #%i: %i\n" %(case+1,best))
    print best
