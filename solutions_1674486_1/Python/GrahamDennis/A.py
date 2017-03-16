#!/usr/bin/env python
# encoding: utf-8
"""
A.py
"""

import sys

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in xrange(T):
        N = int(f.readline())
        full_inherits_from = [None for _ in xrange(N)]
        direct_inherits_from = []
        for _ in xrange(N):
            ancestors = map(int, f.readline().split())
            del ancestors[0]
            direct_inherits_from.append(ancestors)
        
        diamond = []
        
        def ancestors(i):
            if full_inherits_from[i] is not None:
                return full_inherits_from[i]
            
            _ancestors = set(direct_inherits_from[i])
            for cls in direct_inherits_from[i]:
                ancestors_i = ancestors(cls - 1)
                if not _ancestors.isdisjoint(ancestors_i):
                    diamond.append(1)
                _ancestors.update(ancestors_i)
            full_inherits_from[i] = _ancestors
            return _ancestors
        
        for i in xrange(N):
            ancestors(i)
        
        print "Case #%i: %s" % (t+1, "Yes" if diamond else "No")

if __name__ == "__main__":
    sys.exit(main())
