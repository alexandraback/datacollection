
from math import sqrt, ceil, trunc

CACHE=True
if CACHE:
    from paldic import *
    def is_palindrome(num):
        if num in trueset:
            return True
        return False
    
    def square_is_palindrome(num):
        if num in trueset2:
            return True
        return False
else:
    trueset = set([])
    falseset = set([])
    def is_palindrome(num):
        if num in falseset:
            return False
        if num in trueset:
            return True
        snum = str(num)
        lsnum = len(snum)
        for i in xrange(0, lsnum / 2):
            if snum[i] != snum[lsnum - i - 1]:
                falseset.add(num)
                return False
        trueset.add(num)
        return True

    trueset2 = set([])
    falseset2 = set([])
    def square_is_palindrome(num):
        if num in falseset2:
            return False
        if num in trueset2:
            return True
        result = is_palindrome(num ** 2)
        if result:
            trueset2.add(num)
        else:
            falseset2.add(num)
        return result

def gen_palindrome1(snum):
    lnum = len(snum)
    if lnum == 1:
        return snum
    return snum + snum[lnum-2::-1]

def gen_palindrome2(snum):
    return snum + snum[::-1]

def get_seed1(snum):
    lnum = len(snum)
    tlen = lnum / 2 + lnum % 2
    return '1' + '0' * (tlen-1)
    return snum[:tlen]

def get_seed2(snum):
    lnum = len(snum)
    tlen = lnum / 2 + lnum % 2
    return '9' * tlen

def fairsquare_slow(start, end):
    qstart = int(ceil(sqrt(start)))
    qend = trunc(sqrt(end))
    #print start, end, '------------'
    c = 0
    for rt in xrange(qstart, qend + 1):
        if is_palindrome(rt) and square_is_palindrome(rt):
            c += 1
            #print rt, rt**2
    return c

def fairsquare(start, end):
    qstart = int(ceil(sqrt(start)))
    qend = trunc(sqrt(end))

    sstart = get_seed1(str(qstart))
    send = get_seed2(str(qend))
    c = 0
    #print start, end, '------------'
    gen_pal2 = gen_palindrome2
    for seed in xrange(int(sstart), int(send) + 1):
        sseed = str(seed)
        pal = int(gen_palindrome1(sseed))
        if pal > qend:
            break
        if qstart <= pal:
            if square_is_palindrome(pal):
                #print pal, pal ** 2
                c += 1
        pal = int(gen_pal2(sseed))
        if pal > qend:
            gen_pal2 = lambda x: 0
        elif qstart <= pal:
            if square_is_palindrome(pal):
                #print pal, pal ** 2
                c += 1
    return c

if __name__ == '__main__':
    count = input()
    for x in xrange(1, count + 1):
        start, end = map(int, raw_input().split(' '))
        count = fairsquare(start, end)
        print 'Case #%d:' % x, count

