#!/usr/bin/env python

def r(s,k):
    return ''.join('+' if x=='-' else '-'
                   for x in reversed(s[:k])) + \
                       s[k:]
    
def f(s):
    if s.count('-') == 0: return 0
    q = [(s,0)]
    done = set(s)
    while True:
        x,d = q.pop(0)
        for k in xrange(1,len(x)+1):
            y = r(x,k)
            if y not in done:
                if y.count('-') == 0: return d+1
                q.append((y,d+1))
                done.add(y)
def lgs(s):
    i = 0
    while i < len(s) and s[i] == s[0]:
        i += 1
    return i
        
def greedy(s):
    #bruteans = f(s)
    n = len(s)
    ans = 0
    while lgs(s) < n:
        s = r(s,lgs(s))
        ans += 1

    if s.count('-') > 0:
        assert s.count('-') == n
        ans += 1
        
    #assert ans == bruteans
    return ans

'''while True:
    x = raw_input()
    print x, greedy(x)
for x in xrange(2**10):
    b = bin(x)[2:].zfill(10)
    s = ''.join({'0':'+','1':'-'}[a] for a in b)
    print s, greedy(s)
'''
T = input()
for i in xrange(1, T+1):
    print 'Case #{}:'.format(i), greedy(raw_input())
        
        
    
