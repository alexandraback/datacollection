#!/usr/bin/env python3

import sys, math

def computeProbString (fkeys, nkeys, target):
    logp = 0.0
    for letter in target:
        if letter not in fkeys:
            return 0
        else:
            logp = logp + math.log(fkeys[letter]/nkeys)
    return math.exp(logp)

def computeBestString (ntarget, target, msize):
    if msize < ntarget:
        return 0 #, '')
    if msize == ntarget:
        return 1 #(1, target)
    # Now if the monkey types more letters than the size of the target
    # Search for the longest suffix that is also a preffix of the word
    spref = 0
    for s in range (1, ntarget):
        if target[s:] == target[:-s]:
            spref = s
            break
    if spref == 0:
        ntimes = msize//ntarget
        #return (ntimes, target*ntimes)
        return ntimes
    else:
        suf = target[s:]
        ntimes = (msize - ntarget) // (ntarget - s)
        beststr = target[:-s] + (target[s:] * ntimes)
        #return (ntimes, beststr)
        return ntimes

def computeTargetTimes (string, ns, target):
    nt = len(target)
    count = 0
    for i in range (ns - nt + 1):
        if ''.join(string[i:i+nt]) == target:
            count += 1
    return count

acc = 0.0
def backtracking (msize, csize, string, target, fkeys, nkeys, maxbananas):
    if csize == msize:
        #print (string)
        p = computeProbString (fkeys, nkeys, string)
        #print ("p = %f" % p)
        t = computeTargetTimes (string, msize, target)
        #print ("t = %d" % t)
        global acc
        acc = acc + p * (maxbananas - t)
    else:
        for l in fkeys:
            string[csize] = l
            backtracking (msize, csize+1, string, target, fkeys, nkeys, maxbananas)

def solve (nkeys, ntarget, smonkey, keyboard, target):
    freqkeys = {}
    for letter in keyboard:
        if letter in freqkeys:
            freqkeys[letter] += 1
        else:
            freqkeys[letter] = 1

    for letter in target:
        if letter not in freqkeys:
            return 0

    times = computeBestString (ntarget, target, smonkey)
    #print ("times = %d" % times)
    if times == 0:
        return 0
    string = [' ' for _ in range(smonkey)]
    global acc
    acc = 0.0
    backtracking (smonkey, 0, string, target, freqkeys, nkeys, times)
    """if times == 0:
        return 0
    p = computeProbBestString (freqkeys, nkeys, bestStr)
    if p == 0:
        return 0
    res = times - p * times
    return res"""

if __name__ == "__main__":

    T = int (sys.stdin.readline())
    for t in range(1, T+1):
        K, L, S = map(int, sys.stdin.readline().split())
        keyboard = sys.stdin.readline().strip()
        target = sys.stdin.readline().strip()
        solve(K, L, S, keyboard, target)
        print ("Case #%d: %f" % (t, acc))
