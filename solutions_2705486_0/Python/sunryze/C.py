# Google Code Jam 2013, Round 1B, Problem C
#


import sys, re
from heapq import heappush, heappop


''' Wikipedia
def levenshtein(seq1, seq2):
    oneago = None
    thisrow = range(1, len(seq2) + 1) + [0]
    for x in xrange(len(seq1)):
        twoago, oneago, thisrow = oneago, thisrow, [0] * len(seq2) + [x + 1]
        for y in xrange(len(seq2)):
            delcost = oneago[y] + 1
            addcost = thisrow[y - 1] + 1
            subcost = oneago[y - 1] + (seq1[x] != seq2[y])
            thisrow[y] = min(delcost, addcost, subcost)
    return thisrow[len(seq2) - 1]
'''

def dist(s, t):
    last = -5
    d = 0
    for i in xrange(len(s)):
        if s[i] != t[i]:
            if i - last < 5:
                return -1
            else:
                last = i
                d += 1
    return d

def findw(w, trie):
    '''return all words in trie that have prefix w with errors at most every 5th char.'''
    wl = [(0, trie, -5, 0)]
    l = len(w)
    result = []
    while len(wl) > 0:
        depth, t, lasterr, numerr = wl.pop()
        val = t.get('$')
        if val is not None:
            result.append((val, numerr))
        if depth >= l:
            continue
        for c in t:
            #print c, depth, w[depth], lasterr
            if c != '$':
                if c == w[depth]:
                    wl.append((depth+1, t[c], lasterr, numerr))
                elif depth - lasterr >= 5:
                    wl.append((depth+1, t[c], depth, numerr+1))
    return result
    
def mktrie(words):
    root = {}
    for w in words:
        t = root
        for c in w:
            if c not in t:
                t[c] = {}
            t = t[c]
        t['$'] = w
    return root

def solve(num, word, dct):
    wl = [(0, word, 0)]
    best = 1 << 30
    while len(wl) > 0:
        prio, rem, cost = heappop(wl)
        print len(wl), best, rem
        if rem == '':
            best = min(best, cost)
            if best == 0:
                return 0
            # clean up wl
            wl = sorted([ (p,w,c) for (p,w,c) in wl if c < best ])
            continue
        for w in dct:
            l = len(w)
            if len(rem) >= l:
                d = dist(rem[:l], w)
                if d >= 0:
                    c2 = cost + d
                    if c2 < best:
                        rem2 = rem[l:]
                        heappush(wl, (c2+len(rem2), rem2, c2))
    return best

def solve2(num, word, trie):
    wl = [(0, word, 0)]
    best = 1 << 30
    count = 0
    while len(wl) > 0:
        count += 1
        prio, rem, cost = heappop(wl)
        #print len(wl), best, rem
        if rem == '':
            best = min(best, cost)
            if best == 0:
                return 0
            # clean up wl
            wl = sorted([ (p,w,c) for (p,w,c) in wl if c < best ])
            continue
        ws = findw(rem, trie)
        #print ws
        for w, err in ws:
            c2 = cost + err
            rem2 = rem[len(w):]
            if c2 < best:
                heappush(wl, (c2+len(rem2)*len(rem2), rem2, c2))
        if count > 10**3: 
            break
    return best

    
def main(filename):
    words = open('garbled_email_dictionary.txt').readlines()
    trie = mktrie([w.strip() for w in words])
    # words = [w.strip() for w in sorted(words, key=len, reverse=True)]
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(1, total+1):
            w = f_in.readline().strip()
            #print 'Case #{0}: {1}'.format(i, solve(i, w, words))
            print 'Case #{0}: {1}'.format(i, solve2(i, w, trie))
            

if __name__ == "__main__":
    main(sys.argv[1])

    
    