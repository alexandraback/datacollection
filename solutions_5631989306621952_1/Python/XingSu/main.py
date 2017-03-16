import sys

sys.stdin = open("A-large.in", "r")
sys.stdout = open("out.txt", "w")

T = input()
for cas in xrange(1, T+1):
    s = raw_input()
    temp = ""
    for ch in s:
        if temp + ch >= ch + temp:
            temp = temp + ch
        else:
            temp = ch + temp
    print "Case #%d: %s" % (cas, temp)
