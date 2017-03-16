import sys

def solve(seq):
    index=-1
    for i in xrange(len(seq)-1,-1,-1):
        if seq[i]=='-':
            index = i
            break
    if index==-1:
        return 0
    if seq[0]=='+':
        f=0
        for i in xrange(1,len(seq)):
            if seq[i]=='-':
                f=i
                break
        s = '-'*(f)
        s = s+seq[f:]
        return 1+solve(s)


    s = seq[0:index+1]
    for i in xrange(0, len(s)):
        if s[i]=='-':
            s=s[0:i]+'+'+s[i+1:]
        else:
            s=s[0:i]+'-'+s[i+1:]

    return 1+solve(s[::-1])



m = int(raw_input())
for i in xrange(1,m+1):
    n = raw_input()
    print "Case #%d: %d" % (i,solve(n))
