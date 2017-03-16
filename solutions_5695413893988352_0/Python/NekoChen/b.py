import sys, numpy as np
from itertools import combinations
from operator import itemgetter
from collections import deque, defaultdict

def fo_gt( a, b, k ):
    for i in range(k, len(a)):
        if a[i] == None:
            a[i] = 0
        if b[i] == None:
            b[i] = 9

def fo_lt( a, b, k ):
    for i in range(k, len(a)):
        if a[i] == None:
            a[i] = 9
        if b[i] == None:
            b[i] = 0

def ba_eq( a, b, k ):
    for i in range(k-1, -1, -1):
        if a[i] == None:
            if b[i] == None:
                a[i], b[i] = 0, 0
            else:
                a[i] = b[i]
        if b[i] == None:
            b[i] = a[i]

def ba_plus( a, b, k ):
    n = 0
    for i in range(k-1, -1, -1):
        if a[i] == b[i]:
            if a[i] != None:
                continue
            else:
                a[i], b[i] = 1, 0
                n = i
                break
        else:
            if a[i] == None:
                a[i] = b[i]+1
                n = i
                break
            if b[i] == None:
                b[i] = a[i]-1
                n = i
                break
    ba_eq( a, b, n )

def find_fork( a, b ):
    for i in range(len(a)):
        if a[i] == None or b[i] == None or a[i] == b[i]: 
            continue
        return i, (1 if a[i]>b[i] else -1)
    return len(a), 0

def fork( a, b, k ):
    a1, b1 = map(list, (a,b))
    a2, b2 = map(list, (a,b))
    a3, b3 = map(list, (a,b))
    a4, b4 = map(list, (a,b))
    a5, b5 = map(list, (a,b))
    a6, b6 = map(list, (a,b))
    fo_gt( a1, b1, k+1 )
    fo_gt( a2, b2, k+1 )
    fo_gt( a3, b3, k+1 )
    fo_gt( b4, a4, k+1 )
    fo_gt( b5, a5, k+1 )
    fo_gt( b6, a6, k+1 )
    ba_eq( a1, b1, k )
    ba_plus( a2, b2, k )
    ba_plus( b3, a3, k )
    ba_eq( a4, b4, k )
    ba_plus( a5, b5, k )
    ba_plus( b6, a6, k )
    ans = map( makeans, [a1, a2, a3, a4, a5, a6], [b1, b2, b3, b4, b5, b6] )
    #for i in ans:
    #    print i
    return min(ans)

def makeans( a, b ):
    sa = "".join( map(str, a) )
    sb = "".join( map(str, b) )
    diff = abs( int(sa) - int(sb) )
    return diff, int(sb), sa, sb

def solve( a, b ):
    k, sign = find_fork( a, b )
    #print "input", a, b
    #print "k, sign", k, sign
    if sign == 0:
        assert( k == len(a) )
        ba_eq( a, b, k )
        ans = makeans( a, b )
        #print ans
        return ans[2] + " " + ans[3]
    else:
        ans = fork( a, b, k )
        #print ans
        return ans[2] + " " + ans[3]

def main():
    f = open( sys.argv[1] )
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        S = f.next().strip().split()
        T = lambda s: [ None if c=='?' else int(c) for c in s ]
        print "Case #{0}: {1}".format( case, solve( *map(T,S) ) )
        

if __name__ == "__main__":
    main()
