#!/usr/bin/env python

from sys import stdin, stderr

def double(S):
    if len(S) == 0: return []
    if len(S) == 1: return S
    ret = None
    fst = set()
    sec = set()
    fst_cnt = dict()
    sec_cnt = dict()
    for s in S:
        if s[0] in fst:
            fst_cnt[s[0]] += 1
        else:
            fst.add(s[0])
            fst_cnt[s[0]] = 1
            pass
        if s[1] in sec:
            sec_cnt[s[1]] += 1
        else:
            sec.add(s[1])
            sec_cnt[s[1]] = 1
            pass
        pass

    for s in list(S):
        if fst_cnt[s[0]] == 1 or sec_cnt[s[1]] == 1:
            ret = s
            break
        pass

    if ret == None:
        for s in list(S):
            if fst_cnt[s[0]] % 2 == 1 and sec_cnt[s[1]] % 2 == 1:
                ret = s
                break
            pass
        pass

    if ret == None: ret = S[0]

    fst.remove(ret[0])
    sec.remove(ret[1])

    S_next = []
    for s in list(S):
        if s[0] in fst and s[1] in sec:
            S_next.append(s)
            pass
        pass

    return [s] + double(S_next)


def Solve(S):
    fst = set()
    sec = set()
    fst_cnt = dict()
    sec_cnt = dict()
    for s in S:
        if s[0] in fst:
            fst_cnt[s[0]] += 1
        else:
            fst.add(s[0])
            fst_cnt[s[0]] = 1
            pass
        if s[1] in sec:
            sec_cnt[s[1]] += 1
        else:
            sec.add(s[1])
            sec_cnt[s[1]] = 1
            pass
        pass

    for s in list(S):
        if fst_cnt[s[0]] == 1 or sec_cnt[s[1]] == 1:
            if s[0] in fst: fst.remove(s[0])
            if s[1] in sec: sec.remove(s[1])
            #print '1kai:', s
            del S[S.index(s)]
            pass
        pass

    double_kouho = []
    for s in list(S):
        if s[0] in fst and s[1] in sec:
            # fst.remove(s[0])
            # sec.remove(s[1])
            # print 'double:', s
            # del S[S.index(s)]
            double_kouho.append(s)
            pass
        pass
    #print double_kouho

    # print 'nokori:', S
    # print 'fst:', fst
    # print 'sec:', sec
    # return len(S) - len(fst) - len(sec)

    return len(S) - len(fst) - len(sec) + len(double(double_kouho))



for T in range(int(stdin.readline())):
    N = int(stdin.readline())
    S = []
    for n in range(N):
        S.append(stdin.readline().split())
        pass

    print 'Case #%d:' % (T+1),
    #print S
    print Solve(S)
