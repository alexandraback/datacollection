import sys

def chooserwins():
    print "Case #%d: RICHARD" % (t+1) # The X-omino chooser wins
def chooserloses():    
    print "Case #%d: GABRIEL" % (t+1) # The X-omino chooser loses
def boardmatch(n,m):
    return (R == n and C == m) or (R == m and C == n)

def check(X,R,C):
    if R*C % X != 0:
        chooserwins()
        return
    if X >= 7:
        chooserwins()
        return
    if X <= 2:
        chooserloses()
        return
    #======================================
    if X == 3:
        if min(R,C) == 1:
            chooserwins()
            return
        else:
            chooserloses()
            return
    if X == 4:
        if boardmatch(2,2) or boardmatch(2,4) or boardmatch(1,4): 
            chooserwins()
            return
        else:
            chooserloses()
            return


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(0,T):
        string = sys.stdin.readline().split(' ')
        X = int(string[0])
        R = int(string[1])
        C = int(string[2].rstrip())
        #======================================
        check(X,R,C)
