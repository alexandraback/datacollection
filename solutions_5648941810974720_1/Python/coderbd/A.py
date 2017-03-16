#!/usr/bin/python

t = int(raw_input())
for case_no in xrange(1, t+1):
    s = raw_input()
    d = {}
    for c in s:
        d[c] = d.get(c, 0) + 1

    zero = d.get('Z', 0)
    eight = d.get('G', 0)
    four = d.get('U', 0)
    two = d.get('W', 0)
    six = d.get('X', 0)
    three = d.get('H', 0) - eight
    five = d.get('F', 0) - four
    seven = d.get('S', 0) - six
    nine = d.get('I', 0) - five - six - eight
    one = d.get('O', 0) - zero - two - four

    ans = ''
    ans += '0' * zero
    ans += '1' * one
    ans += '2' * two
    ans += '3' * three
    ans += '4' * four
    ans += '5' * five
    ans += '6' * six
    ans += '7' * seven
    ans += '8' * eight
    ans += '9' * nine

    print 'Case #%d: %s' % (case_no, ans)
