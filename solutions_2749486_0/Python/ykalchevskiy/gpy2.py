def f(test):
    x, y = map(int, raw_input().split())
    res = ''
    if x > 0:
        res += 'WE' * x
    elif x < 0:
        res += 'EW' * -x
    if y > 0:
        res += 'SN' * y
    elif y < 0:
        res += 'NS' * -y
    
    print "Case #" + str(test) + ': ' + str(res)


t = int(input())
for _ in xrange(t):
    f(_ + 1)
