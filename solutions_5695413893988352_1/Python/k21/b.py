#!/usr/bin/env python3

def can_be_equal(c1, c2):
    return c1 == '?' or c2 == '?' or c1 == c2

def can_be_lower(c1, c2):
    if c1 == '?': return c2 != '0'
    if c2 == '?': return c1 != '9'
    return c1 < c2

def make_lower(c1, c2):
    assert can_be_lower(c1, c2)
    if c1 == '?' and c2 == '?': return '0', '1'
    if c1 == '?': return chr(ord(c2) - 1), c2
    if c2 == '?': return c1, chr(ord(c1) + 1)
    return c1, c2

def make_max(c):
    if c == '?': return '9'
    else: return c

def make_min(c):
    if c == '?': return '0'
    else: return c

def assume_first_lower_or_eq(s1, s2, same):
    p1 = p2 = ''
    l = len(s1)
    i = 0
    while i < same and can_be_equal(s1[i], s2[i]):
        if s1[i] == '?' and s2[i] == '?':
            p1 += '0'
            p2 += '0'
        elif s1[i] == '?':
            p1 += s2[i]
            p2 += s2[i]
        else:
            p1 += s1[i]
            p2 += s1[i]
        i += 1
    if i < same: return None, None
    if i == l: return p1, p2
    if not can_be_lower(s1[i], s2[i]): return None, None
    c1, c2 = make_lower(s1[i], s2[i])
    p1 += c1
    p2 += c2
    i += 1
    while i < l:
        p1 += make_max(s1[i])
        p2 += make_min(s2[i])
        i += 1
    return p1, p2

def select_better(a1, a2, b1, b2):
    if a1 is None: return b1, b2
    if b1 is None: return a1, a2
    diff_a = abs(int(a1) - int(a2))
    diff_b = abs(int(b1) - int(b2))
    if diff_a < diff_b: return a1, a2
    if diff_a > diff_b: return b1, b2
    if int(a1) < int(b1): return a1, a2
    if int(a1) > int(b1): return b1, b2
    if int(a2) < int(b2): return a1, a2
    return b1, b2

def matches(s, pattern):
    if len(s) != len(pattern): return False
    for i in range(len(pattern)):
        if s[i] != pattern[i] and pattern[i] != '?': return False
    return True

T = int(input())
for t in range(T):
    s1, s2 = input().split()
    while len(s1) < len(s2):
        s1 = '0' + s1
    while len(s2) < len(s1):
        s2 = '0' + s2
    if False:
        cand = [str(x).rjust(len(s1), '0') for x in range(10**len(s1))]
        cand1 = [x for x in cand if matches(x, s1)]
        cand2 = [x for x in cand if matches(x, s2)]
        a1, a2 = None, None
        for t1 in cand1:
            for t2 in cand2:
                a1, a2 = select_better(a1, a2, t1, t2)
    else:
        a1, a2 = None, None
        for i in range(len(s1)+1):
            b1, b2 = assume_first_lower_or_eq(s1, s2, i)
            a1, a2 = select_better(a1, a2, b1, b2)
            b2, b1 = assume_first_lower_or_eq(s2, s1, i)
            a1, a2 = select_better(a1, a2, b1, b2)
    print('Case #{}: {} {}'.format(t+1, a1, a2))
