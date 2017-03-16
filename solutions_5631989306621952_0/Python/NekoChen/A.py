import sys

from itertools import combinations
from operator import itemgetter
from collections import deque

def solve( S ):
    a = deque()
    for c in S:
        if len(a)==0 or c >= a[0]:
            a.appendleft(c)
        else:
            a.append(c)
    return "".join(a)

def main():
    f = open( sys.argv[1] )
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        S = f.next().strip()
        print "Case #{0}: {1}".format( case, solve(S) )
        

if __name__ == "__main__":
    main()
