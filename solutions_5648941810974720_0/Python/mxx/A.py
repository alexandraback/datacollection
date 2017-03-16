def testcase(ind): # Getting the Digits
    S = raw_input()
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
        
    

english = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
strings = { 1: tuple(map(str,range(10))) }

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

if __name__=='__main__':
    T = int(raw_input())
    for i in xrange(T):
        testcase(i+1)
