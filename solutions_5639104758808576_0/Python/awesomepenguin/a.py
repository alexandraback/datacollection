t = int(raw_input())
for i in xrange(1, t+1):
    [_, a] = raw_input().split()
    a = str(a)
    
    required = 0
    current = 0
    for shyness, num2 in enumerate(a):
        num = int(num2)
        if current < shyness:
            required += (shyness - current)
            current = shyness
        current += num
    print 'Case #%d: %d' % (i, required)
