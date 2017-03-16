english = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
strings = { 
1: tuple(map(str,range(10))) }

def gen_str(l):# generate string with non-descreasing digits, of length=l 
    if l in strings: return strings[l]
    else: 
        res = []
        strs_l1 = gen_str(l-1)
        for s in strs_l1:
            d = int(s[-1])
            for i in xrange(d, 10):
                res.append(s+str(i))
        strings[l] = tuple(res)
        return res

def digstr2english(s):
    res = ''
    for c in s:
        res += english[int(c)]
    return res


def testcase_small(ind): # Getting the Digits --> SB method...
    S = raw_input() 
    S *= 100
    S = ''.join( sorted(S) )
    from collections import Counter
    ctr = Counter(S)
    finished = False
    for l in xrange(1,1000):
        if finished: return
        for digstr in gen_str(l):
            engstr = digstr2english(digstr)
            if len(engstr)!=len(S): continue
            if ''.join( sorted(engstr) ) == S: 
                print 'Case #%d: %s' % (ind, digstr)
                finished = True
                break

def testcase(ind): # Getting the Digits --> very cleaver method 
    order = map(int, '0684753219') # **magic order**  with this order never need backtrack !! ;)
    S = raw_input() 
    from collections import Counter
    ctr = Counter(S)
    nbs = {i:0 for i in xrange(10)}
    def can_have(n): # with the current counter can we have enough letters for number n?
        for c in english[n]:
            if ctr[c]<=0: return False
        return True
    for n in order:
        while can_have(n):
            nbs[n] += 1
            for c in english[n]:
                ctr[c] -= 1
    res = ''
    for n in xrange(10): res += str(n)*nbs[n]
    print 'Case #%d: %s' % (ind, res)


if __name__=='__main__':
    T = int(raw_input())
    for i in xrange(T):
        testcase(i+1)
