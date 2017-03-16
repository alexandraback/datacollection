from math import *

t = int(raw_input())
for i in range(t):
    s = raw_input()
    c = [0] * 26
    for x in s:
        c[ord(x) - ord('A')] += 1
    r = []
    for x in ('Z', 'W', 'U', 'X', 'G'):
        if c[ord(x) - ord('A')] > 0:
            let = 0
            if x == 'Z':
                let = 0
                c[ord('E') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('R') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('O') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'W':
                let = 2
                c[ord('T') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('O') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'U':
                let = 4
                c[ord('F') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('O') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('R') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'X':
                let = 6
                c[ord('S') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('I') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'G':
                let = 8
                c[ord('E') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('I') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('H') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('T') - ord('A')] -= c[ord(x) - ord('A')]
            for j in range(c[ord(x) - ord('A')]):
                r.append(let)
            c[ord(x) - ord('A')] = 0
    for x in ('S', 'H', 'F', 'O', 'I'):
        let = 0
        if c[ord(x) - ord('A')] > 0:
            if x == 'S':
                let = 7
                c[ord('E') - ord('A')] -= 2 * c[ord(x) - ord('A')]
                c[ord('V') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('N') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'H':
                let = 3
                c[ord('T') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('R') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('E') - ord('A')] -= 2 * c[ord(x) - ord('A')]
            if x == 'I':
                let = 9
                c[ord('E') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('N') - ord('A')] -= 2 * c[ord(x) - ord('A')]
            if x == 'O':
                let = 1
                c[ord('N') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('E') - ord('A')] -= c[ord(x) - ord('A')]
            if x == 'F':
                let = 5
                c[ord('I') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('V') - ord('A')] -= c[ord(x) - ord('A')]
                c[ord('E') - ord('A')] -= c[ord(x) - ord('A')]
            for j in range(c[ord(x) - ord('A')]):
                    r.append(let)
            c[ord(x) - ord('A')] = 0
    r = sorted(r)
    rs = ""
    for x in r:
        rs += str(x)
    print "Case #" + str(i + 1) + ": " + rs

