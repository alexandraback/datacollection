#!/usr/bin/python

def f(k, r):
    return 2*k*(k+1) + (k+1) * (2*r + 1)


def getrings(r, paint):
    maxx = 10**10
    minn = 0
    while maxx != minn:
        guess = (maxx + minn + 1)/2
        if f(guess, r) > paint:
            maxx = guess - 1
        else:
            minn = guess
            if f(guess + 1, r) <= paint:
                minn = guess + 1
#        print guess
    maxx = correctbadbinarysearch(r, paint, maxx)
    return maxx

#actually bin search not bad
def correctbadbinarysearch(r, paint, guess):
    ans = 0
    for k in range(guess - 3, guess + 3):
        if f(k, r) <= paint:
            ans = k
    return ans

#small input
def getmaxrings(r, paint):
    tot = (r+1)**2 - r**2
    add = 1
    while tot <= paint:
        add += 2
        tot = tot + (r+add)**2 - (r+add-1)**2

    return add/2

cases = int(raw_input())

for casenum in range(1, cases + 1):
    line = raw_input()
    r = int(line.split()[0])
    t = int(line.split()[1])
    print "Case #{}: {}".format(casenum, getrings(r, t)+1)
