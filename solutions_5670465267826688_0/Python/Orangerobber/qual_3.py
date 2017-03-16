import sys

T = int(sys.stdin.readline())

Q = [[1,2,3,4],[2,-1,4,-3],[3,-4,-1,2],[4,3,-2,-1]]

def qmult(a,b):
    return (a/abs(a)) * (b/abs(b)) * Q[abs(a)-1][abs(b)-1]

def q_int(st):
    if(st=='1'):
        return 1
    if(st=='i'):
        return 2
    if(st=='j'):
        return 3
    if(st=='k'):
        return 4
    print "Error."

def quat(st):
    m = 1
    for i in st:
        m = qmult(m,i)
    return m

def check_extras(X,xv,ex, base):
    if(X < sum(ex) + base):
        return False
    left = X - sum(ex) - base
    if(xv == 1):
        return True
    elif(xv == -1):
        if(left % 2 == 0):
            return True
        else:
            return False
    else:
        if(left % 4 == 0):
            return True
        else:
            return False


for t in range(T):
    L, X = [int(x) for x in sys.stdin.readline().split()]
    st = sys.stdin.readline().strip()

    #print st, X
    ijk = [q_int(x) for x in list(st)]
    
    # we now want to work out val(x:y) for x = 0:L-1, y=1:L
    
    xv = quat(ijk)
    WRONG_PROD = False
    if (xv == 1):
        WRONG_PROD = True
    elif(xv == -1):
        if(X %2 == 0):
            WRONG_PROD = True
    else:
        if not(X % 4 == 2):
            WRONG_PROD = True
    if(WRONG_PROD):
        print "Case #%d: NO"%(t+1)
        continue



    POSS = False
    for s1 in range(0,L+1):
        extras = [0,0,0]
        v1 = quat(ijk[:s1])
        if(s1 == 0):
            v1 = 1
        v = v1
        p = False
        while extras[0] < 3:
            if(v == 2):
                p = True
                break
            v = qmult(xv, v)
            extras[0] += 1
        if not (p) or sum(extras)+1> X:
            #print "i fail", s1, s2
            continue
        #else:
        #    print "i success", s1, s2

        for s2 in range(0,L+1):
            extras[1] = 0
            extras[2] = 0

            v3 = quat(ijk[s2:])
            if(s2 == L):
                v3  = 1
            v = v3
            p = False
            while extras[2] < 3:
                if(v == 4):
                    p = True
                    break
                v = qmult(v, xv)
                extras[2] += 1
            if not (p) or sum(extras)+1> X:
                #print "k fail", s1, s2
                continue
            #else:
                #print "k success", s1, s2

            # for j there are several possibilities

            p = False
            if(s2>s1):
                v2 = quat(ijk[s1:s2])
                v2p = qmult(quat(ijk[s1:]), quat(ijk[:s2]))
                v2pp = qmult(qmult(quat(ijk[s1:]), xv), quat(ijk[:s2]))
                if(v2 == 3):
                    p = True
                elif(v2p == 3):
                    extras[1] += 1
                    p = True
                elif(v2pp == 3):
                    extras[1] += 2
                    p = True
                if(p):
                    #print extras
                    if(check_extras(X,xv, extras, 1)):
                        POSS = True
                        #print "j success", s1, s2
                        break
                    else:
                        continue
                else:
                    #print "j fail", s1, s2
                    continue
            else:
                v2a = quat(ijk[s1:])
                v2b = quat(ijk[:s2])
                v2 = qmult(v2a, v2b)
                v2p = qmult(qmult(v2a,xv),v2b)
                
                if(v2 == 3):
                    p = True
                elif(v2p == 3):
                    extras[1] += 1
                    p = True
                elif(v2 == -3):
                    extras[1] += 2
                    p = True
                if(p):
                    #print extras
                    if(check_extras(X,xv, extras, 2)):
                        POSS = True
                        #print "j success", s1, s2
                        break
                    else:
                        continue
                else:
                    #print "j fail", s1, s2
                    continue
        if(POSS):
            break

    if(POSS):
        print "Case #%d: YES"%(t+1)
    else:
        print "Case #%d: NO"%(t+1)



    #we need for j to be one of val, or 