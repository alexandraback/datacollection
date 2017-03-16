#! /usr/bin/env python

#import math

#  +---+---+---+
#  | a | b | c |
#  +---+---+---+
#  0   1   2   3
# -3  -2  -1

# int ( input() )
# L = map ( int, input().split() )
# sum (... for i,y in enumerate(L))
# L[:] # list copy
# L1 + L2 # list concatenation
# set(), list()
# F = [i for i, v in enumerate(L) if v == ...]
# L.remove(element)

def train(i,S,T,C,l,N):
    # s = current string
    # i = index of current string
    # S = strings
    # T = taken strings
    # C = set of chars
    # l = last char
    # N = numer of strings
    #print('current: %s' % S[i])
    T[i] = 1 # current string is taken
    if all(b == 1 for b in T):
        ##print('good')
        return 1
    else:
        #print('still going')
        c = 0
        for j in range(N):
            if (T[j] == 0):
                #print('next: %s' % S[j])
                Cj = set(S[j])
                if ( len(C.intersection(Cj)) == 0 ):
                    #print('first')
                    c = c + train(j,S,T.copy(),C.union(Cj),S[j][-1],N)
                else:
                    Cj.remove(S[j][0])
                    if (S[j][0] == l and len(C.intersection(Cj)) == 0): # assume single strings are valid
                        #print('second')
                        c = c + train(j,S,T.copy(),C.union(Cj),S[j][-1],N)
                    #else:
                        #print('last')
        return c

T = int( input() )

for x in range(1,T+1):
     
    N = int ( input() )
    S = input().split()
    T = [0 for i in range(N)]
    
    c = 0
    for i in range(N):
        c = c + train(i,S,T.copy(),set(S[i]),S[i][-1],N)

    #M = [[0 for i in range(N)] for j in range(N)]
    #for i in range(N):
    #    for j in range(1,N):
    #        L1 = set(S[i])
    #        L2 = set(S[j])
    #        if (L1 != L2):
    #            M[i][j] = 1
    #            M[j][i] = 1
    #        else if (L1.remove(S[i][-1]) != L2.remove(S[j][0])):
    #            M[i][j] = 1
    #        else if (L2.remove(S[j][-1]) == L1.remove(S[i][0])):
    #            M[j][i] = 1     
    
    print('Case #%i: %i' % (x,c))
