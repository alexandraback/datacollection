#! /usr/bin/python

import os, sys

T = int(raw_input())

# For each test case
for t in range(1, T+1):
    [A, N] = [int(x) for x in raw_input().split(' ')]
    motes = [int(x) for x in raw_input().split(' ')]
    motes.sort()
    #print "%s %s" % (A, N)
    #print "%s" % motes

    have = A
    need_more = []
    check_until = N
    i = 0
    for mote in motes:
        i += 1
        if have > mote:
            have += mote
            need_more.append(0)
        else:
            if have == 1 :
                need_more.append(-1)
                check_until = i - 1
                break
            needs_for_this = 0
            while have < mote + 1:
                have += (have - 1)
                needs_for_this += 1
            have += mote
            need_more.append(needs_for_this)
    balance = 0
    i = 0
    trim = N
    for cost in need_more:
        i += 1
        if cost > 1 and balance == 0:
            balance += cost - 1
            trim = i
        elif cost > 1:
            balance += cost - 1
        elif cost == 0 and balance > 0:
            balance -= 1
            if balance == 0:
                trim = N
    #print 'balance %s ' % balance
    #print 'trim %s ' % trim
    #print 'check_until %s ' % check_until

    #print need_more
    total = 0
    if balance > 0:
        cut_of = check_until - trim + 1
        s = 0
        up = len(need_more) - cut_of
        #print 'up: %s' % up
        #print need_more
        for c in need_more[0:up]:
            #print 'add %s ' % c
            s += c
        total = s + cut_of + (N - check_until)
        #print "%s" % cut_of
        #print "%s" % s
    else:
        s = 0
        for c in need_more[0:check_until]:
            s += c
        total = s + (N - check_until)

    print 'Case #%s: %s' % (t, total)
