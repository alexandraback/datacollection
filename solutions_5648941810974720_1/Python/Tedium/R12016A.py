from string import *

f = open('A-large.in', 'r')
inp = f.read().split("\n")
f.close()

inds = {}
for i in range(len(ascii_uppercase)):
    inds[ascii_uppercase[i]] = i

T = int(inp[0])

def update (c, k, num):
    count = c[inds[k]]
    for i in num:
        c[inds[i]] -= count
    return (count, c)

for itr in range(1, T+1):
    s = inp[itr]

    c = [0] * 26
    for i in s:
        c[inds[i]] += 1

    numbs = [0] * 10
    (numbs[0], c) = update(c, 'Z', 'ZERO')
    (numbs[2], c) = update(c, 'W', 'TWO')
    (numbs[6], c) = update(c, 'X', 'SIX')
    (numbs[8], c) = update(c, 'G', 'EIGHT')
    (numbs[4], c) = update(c, 'U', 'FOUR')
    (numbs[3], c) = update(c, 'R', 'THREE')
    (numbs[1], c) = update(c, 'O', 'ONE')
    (numbs[5], c) = update(c, 'F', 'FIVE')
    (numbs[7], c) = update(c, 'V', 'SEVEN')
    (numbs[9], c) = update(c, 'I', 'NINE')

    out = ""
    for i in range(10):
        out += str(i) * numbs[i]
    print("Case #%d: %s" % (itr, out))
