import sys

N = int(raw_input())

for i in range(N):
    s = raw_input()
    o = s[0]
    for c in s[1:]:
        if c >= o[0]: o = c + o
        else: o += c
    print "Case #%d: %s" %(i+1, o)