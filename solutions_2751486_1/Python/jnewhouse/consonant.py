from Queue import Queue
consonants = "bcdfghjklmnpqrstvwxyz"
for t in range(1, int(raw_input())+1):
    print "Case #"+str(t)+":",
    s, n = raw_input().split()
    n = int(n)
    L = len(s)
    latestStart = -1
    total = 0
    currentBlockStart = -1
    for i in range(L):
        if s[i] in consonants:
            if currentBlockStart == -1:
                currentBlockStart = i
            if i - currentBlockStart + 1 >=n:
                latestStart = i-n+1
        else:
            currentBlockStart = -1
        if latestStart >-1:
            total += latestStart + 1
    print total
