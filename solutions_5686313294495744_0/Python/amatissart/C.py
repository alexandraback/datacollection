# -*- coding: utf-8 -*-
import sys
from collections import Counter


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        n_topics = int(f.readline())
        topics = set()
        words1 = Counter()
        words2 = Counter()
        res = 0
        for j in xrange(n_topics):
            w1,w2 = f.readline().split()
            topics.add((w1,w2))
            words1.update([w1])
            words2.update([w2])
        topicsn = []
        topicsn2 = []
        for w1,w2 in topics:
            topicsn.append((w1,w2,min(words1[w1],words2[w2])))
            topicsn2.append((w1,w2,max(words1[w1],words2[w2])))
        topicsn.sort(key=lambda (a,b,c):-c)
        topicsn2.sort(key=lambda (a,b,c):-c)
        for w1,w2,_ in topicsn:
            if words1[w1] > 1 and words2[w2] > 1:
                res+=1
                words1[w1] -= 1
                words2[w2] -= 1
        res2 = 0
        words12 = words1.copy()
        words22 = words2.copy()
        for w1,w2,_ in topicsn2:
            if words12[w1] > 1 and words22[w2] > 1:
                res2+=1
                words12[w1] -= 1
                words22[w2] -= 1
        print 'Case #{t}: {r}'.format(t=i+1, r=max(res,res2))
        
