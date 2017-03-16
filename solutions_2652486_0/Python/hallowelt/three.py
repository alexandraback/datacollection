#!/usr/bin/python


def guess(ar):
    div = [2, 3, 4, 5]
    guess = []
    definite = []
    for i in ar:
        if i % 2 == 0 and i % 4 != 0:
            definite += [2]
        if i % 3 == 0:
            definite += [3]
        if i % 5 == 0:
            definite += [5]
    definite = list(set(definite))
    if len(definite) == 3:
        return definite

    d2 = []
    for i in ar:
        if i % 9 == 0:
            d2 += [3]
        if i % 25 == 0:
            d2 += [5]
    d2 = list(set(d2))
    definite += d2
    if len(definite) == 3:
        return definite
    
    freq = [0]*6
    for i in ar:
        x = i
        while x % 3 == 0:
            freq[3] += 1
            x = x/3
        while x % 5 == 0:
            freq[5] += 1
            x = x/5
        while x % 4 == 0:
            freq[4] += 1
            x = x/4
        if x % 2 == 0 and 2 not in definite:
            definite += [2]
    if freq[4] >= 2 and 4 not in definite:
        definite += [4]
    while len(definite) < 3 and max(freq) > 0:
        x = freq.index(max(freq))
        if freq[x]:
            definite += [x]
        if freq[x] == 1:
            freq[x] == 0
        else:
            freq[x] = 1
    while len(definite) < 3:
        definite += [4]
    return definite
        

raw_input()

print "Case #1:"

for _ in range(100):
    s = raw_input()
    ar = [int(i) for i in s.split()]
    ans = guess(ar)
    print "{}{}{}".format(ans[0], ans[1], ans[2])


