#!/usr/bin/python

t = int(raw_input())

def compare(left, right):
    for i in range(len(left)):
        if not left[i] == right[i]:
            return ord(left[i]) - ord(right[i])
    return 0

for i in range(t):
    val = raw_input()
    out = ''
    for char in val:
        left = char + out
        right = out + char
        if compare(left, right) < 0:
            out = right
        else:
            out = left   
    print "Case #" + str(i + 1) + ":", out
