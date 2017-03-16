from itertools import product
T = int(raw_input())

def solve(keyboard, target, S):
    total = 0
    jump = len(target)
    average = 0.0
    sm = 0.0
    for prod in product(keyboard, repeat=S):
        s = ''.join(prod)
        now = s.count(target)
        total += 1
        sm += now
        """
        for i in xrange(0, S, jump):
            out =  s[i:i+jump]
            if out == target:
                print out, i
                cnt += 1
                total += 1
        """
    return sm / total

for tc in xrange(1, 1+T):
    K,L,S = map(int, raw_input().split())
    print K,L,S
    keyboard = raw_input()
    target = raw_input()
    assert len(keyboard) == K
    assert len(target) == L
    e = solve(keyboard, target, S)
    bananas = S / L
    diff = bananas - e

    e = 0.0
    print "Case #%d: %f" % (tc, diff)
