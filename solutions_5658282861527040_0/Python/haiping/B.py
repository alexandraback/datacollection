#/usr/bin/env python2.7
#-*- coding:utf-8 -*-
#huanghaiping2@gmail.com
# vim: ts=4 sts=4 sw=4 et

import sys
from multiprocessing import Process, Queue

def readline():
    return sys.stdin.readline().strip()

def solve(inQueue, outQueue):
    while True:
        paramDict = inQueue.get()
        if paramDict is None:
            return
        A = paramDict['A']
        B = paramDict['B']
        K = paramDict['K']

        count = 0
        for a in xrange(A):
            for b in xrange(B):
                res = a&b
                if res < K:
                    count += 1

        outQueue.put((paramDict['T'], count))


if __name__ == '__main__':
    PROCNUM = 1

    procs = []
    inQueue = Queue()
    outQueue = Queue()

    T = int(readline())
    for t in xrange(T):
        paramDict = {}
        paramDict['T'] = t+1
        A,B,K = [long(i) for i in readline().split(' ')]
        paramDict['A'] = A
        paramDict['B'] = B
        paramDict['K'] = K
        inQueue.put(paramDict)

    for i in xrange(PROCNUM):
        inQueue.put(None)

    if PROCNUM > 1:
        for i in xrange(PROCNUM):
            p = Process(target=solve, args=(inQueue, outQueue))
            p.start()

        for i in xrange(PROCNUM):
            p.join()
    else:
        solve(inQueue, outQueue)

    results = []
    for t in xrange(T):
        result = outQueue.get()
        results.append(result)
    results.sort(key=lambda x:x[0])
    for result in results:
        print 'Case #%s: %s' % (result[0], result[1])

