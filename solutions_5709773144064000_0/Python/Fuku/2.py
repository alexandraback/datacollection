ri = lambda : raw_input().strip()
rim = lambda tp, deli: map(tp, ri().split(deli))

n = int(ri())

for i in xrange(0, n):
    c, f, x = rim(float, ' ')
    rate = 2.0
    next_list = [0.0]
    cost = x / rate
    
    while True:
        next = c / rate
        next_list.append(next)
        rate += f
        next = sum(next_list) + x / rate
        if next < cost:
            cost = next
        else:
            break
    
    print 'Case #{0}: {1}'.format(i+1, cost)
    


