#!/usr/bin/python

import sys, decimal, collections as coll, itertools as it, math, cPickle as pkl

def factor(f):
    if f == 1:
        return 1
    res = 1
    for i in xrange(1,f+1):
        res *= i
        # res %= 1000000007               
    return res



T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    N = int(raw_input())
    
    car = raw_input().split()
        
    # print >>sys.stderr, 'car: ', car

    letters = coll.defaultdict(int)
    fact = coll.defaultdict(int)
    possible  = True
    se = coll.defaultdict(int)
    
    for c in car:
        # print >>sys.stderr, "c:", c
        # se[c[0]] = c[-1]
        
        last_letter = c[0]
        cur = 0
        start = True
        
        if not possible:
            break
        
        for cc in c:
            # print >>sys.stderr, "cc:", cc
            
            if cc == last_letter:
                # print >>sys.stderr, "plusone", cur
                cur += 1
            else:
                if start:
                    start = False
                    # print >>sys.stderr, "start", letters[last_letter]
                    if letters[last_letter] in [-100, 1, 100]:
                        # print >>sys.stderr, 'nnn'
                        possible = False
                        break
                    elif letters[last_letter] == -1:
                        letters[last_letter] = 100
                    else:
                        letters[last_letter] = 1
                        # print >>sys.stderr, "set 1", letters[last_letter], letters
                
                else:
                    # mid
                    if letters[last_letter] in [-100, -1, 1, 100]:
                        # print >>sys.stderr, 'mmm'
                        possible = False
                        break
                    else:
                        letters[last_letter] = -100                        
                cur = 1
                last_letter = cc
                        
        else:
            if start:
                #From start ot end
                if letters[last_letter] not in [-100]:
                    fact[last_letter] += 1
                else: 
                    # print >>sys.stderr, 'fgff'
                    possible = False
            else:
                se[c[0]] = c[-1]
                
                if letters[last_letter] not in [0, 1]:
                    # print >>sys.stderr, ';khadsf'
                    possible = False
                elif letters[last_letter] == 1:
                    letters[last_letter] = 100
                else:
                    letters[last_letter] = -1
    
    if not possible:
        print 0
    else:
        # print >>sys.stderr, 'se', se
        
        for k, v in se.items():
            # print >>sys.stderr, 'k, v, start', k, v
            t = k 
            h = v
        
            while t != 0 and h != 0 and t != h:               
                # print >>sys.stderr, 't', t, se[t]
                # print >>sys.stderr, 'h', h, se[h], se[se[h]]
                t = se[t]
                h = se[se[h]]
                # print >>sys.stderr, 't, h', t, h
        
            # print >>sys.stderr, 'Finally', t, h
            if t != 0 and h != 0 and t == h:
                # print >>sys.stderr, 'NOT POSSIBLE'
                possible = False
                break
                
        if not possible:
            print 0
            continue
        
        # a = True
        # for l in letters:
        #     if l != 100 and l != 0:
        #         a = False
        #         break
        # if a:
        #     # print >>sys.stderr, 'brrr0'
        #     print 0
        # else:
            # print >>sys.stderr, 'Calculate'
            # print >>sys.stderr, 'Letters:', letters, fact
           
        res = 1
        amount = 0
        for k, f in fact.items():
            res *= factor(f)
            # res %= 1000000007
            
            if letters[k] == -100:
                possible = False
                break
            
            if letters[k] not in [-1,1,100]:
                amount +=1
            
        if not possible:
            print 0
            continue
            
        print >>sys.stderr, 'am:', amount, res
        for k, v in letters.items():
            if v == 1:
                amount +=1
        
        print >>sys.stderr, 'am:', amount
        res *= factor(amount)
        res %= 1000000007
        
        print res
            
        
        
        
        
        
        
        
        
        