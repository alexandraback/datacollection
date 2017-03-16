#!/usr/bin/env python

import sys


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    
    for i in range(T):
        S = sys.stdin.readline().strip().split()
        S_max = int(S[0])
        S = list(map(int, S[1]))
        
        additional = 0
        standing = S[0]
        
        for j in range(1, S_max + 1):
            if standing < j:
                additional += j - standing
                standing += j - standing
            standing += S[j]
        
        print('Case #%d: %d' % (i + 1, additional))