#!/usr/bin/env python

import sys

def main():
    T = int(sys.stdin.readline())
    for t in range(1,T+1):
        K,C,S = map(int,sys.stdin.readline().split())
        if C==1:
            if S<K:
                print 'Case #%d: IMPOSSIBLE' % t
            else:
                print 'Case #%d: %s' % (t,' '.join(map(str,range(1,K+1))))
        else:
            limit = K/2 if K%2==0 else K/2+1
            if S<limit:
                print 'Case #%d: IMPOSSIBLE' % t
            else:
                print 'Case #%d: %s' % (t,' '.join(map(str,[min(2*K*i+2*(i+1),K*K) for i in range(limit)])))

main()
