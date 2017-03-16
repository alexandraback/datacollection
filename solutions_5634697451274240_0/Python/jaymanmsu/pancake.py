T = int(raw_input().strip())

for i in range(1,T+1):
    stack = map(lambda x: 1 if x == '+' else -1, raw_input().strip()[::-1])
    times = 0
    for s in xrange(len(stack)):
        if stack[s] == -1:
            for t in xrange(s,len(stack)):
                stack[t] = -stack[t]
            times += 1
    print 'Case #%d: %s' % (i, times)