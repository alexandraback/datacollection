#!/usr/bin/env python

from sys import stdin


def L_sqrt(num):
    it = 1
    ret = 0
    while num >= it**2: it *= 10
    it /= 10
    while it >= 1:
        while num >= ret**2: ret += it
        ret -= it
        it /= 10
        pass
    if ret ** 2 < num: ret += 1
    return ret

def unpack(num):
    ret = []
    while num > 0:
        ret.append(num % 10)
        num /= 10
        pass
    ret.reverse()
    return ret

def pack(st):
    ret = st[0]
    for i in range(len(st)-1):
        ret *= 10
        ret += st[i+1]
        pass
    return ret

def is_fair(st):
    if(type(st) != list): return is_fair(unpack(st))
    n = len(st)
    for i in range((n+1)/2):
        if st[i] != st[n-1-i]: return False
        pass
    return True

def next_fair(st):
    if(type(st) != list): return next_fair(unpack(st))
    n = len(st)
    head = st[0:(n+1)/2]
    if(not is_fair(st)):
        tail = head[:]
        tail.reverse()
        if n % 2 == 0: head.extend(tail[0:])
        else:          head.extend(tail[1:])
        ret = pack(head)
        if ret > pack(st): return ret
        return next_fair(ret)
    nhead = unpack(pack(head) + 1)
    if len(nhead) != len(head): ## kuri agari
        ret = 1
        for i in range(n): ret *= 10
        return next_fair(ret)
    ntail = nhead[:]
    ntail.reverse()
    if n % 2 == 0: nhead.extend(ntail[0:])
    else:          nhead.extend(ntail[1:])
    return pack(nhead)

#print next_fair(unpack(19287))
#exit()

T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    ## read
    A, B = stdin.readline().split()
    A = int(A)
    B = int(B)

    ret = 0
    it = L_sqrt(A)
    if(not is_fair(it)): it = next_fair(it)

    while it ** 2 <= B:
        if(is_fair(it**2)):
            ret += 1
            #print it**2
            pass
        it = next_fair(it)
        pass

    print ret
