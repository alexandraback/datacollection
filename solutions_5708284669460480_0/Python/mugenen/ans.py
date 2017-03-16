import collections
import heapq
import math

T = input()

for t in xrange(T):
    K, L, S = map(int, raw_input().split())
    key = raw_input()
    target = raw_input()
    
    L = len(target)
    
    diff = L
    for i in xrange(1, L):
        temp = target[i:]
        if temp == target[:len(temp)]:
            diff = i
            break
    
    count = collections.Counter()
    for k in key:
        count[k] += 1
    for k in count:
        count[k] /= float(K)
    
    prob = 1.0
    for s in target:
        prob *= count[s]
    
    if S >= L and prob != 0.0:
        BANANA = float((S - L) / diff + 1)
    else:
        BANANA = 0.0
    
    pay = 0.0
    if S >= L:
        pay = prob * (S - L + 1)
#    print diff, BANANA, pay, prob#, count
    result = BANANA - pay
    print 'CASE #{}: {}'.format(t + 1, result)
