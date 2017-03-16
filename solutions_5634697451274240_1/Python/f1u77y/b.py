#! /usr/bin/python

t = int(input())
def inv(s):
    ans = str()
    for c in s:
        ans += chr(ord('+') + ord('-') - ord(c))
    return ans


for tn in range(1, t + 1):
    s = input()
    ans = 0
    while set(s) != {'+'}:
        if s[0] == '-':
            r = s.rindex('-') + 1
        else:
            r = s.index('-')
        s = inv(s[:r][::-1]) + s[r:]
        ans += 1
    print("CASE #%d: %d" % (tn, ans))

