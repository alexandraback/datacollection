def how_many(x, goal):
    if (len(x) == 1):
        if (x[0] == goal):
            return 0
        else:
            return 1

    if (sum(x) == 0): # 0000 goal 0 => 0, goal 1 => 1
        return goal

    if (sum(x) == len(x)): # 1111 goal 0 => 1, goal 1 => 0
        return 1 - goal
    
    last = x[-1]

    for j in reversed(xrange(len(x) - 1)):
        if (x[j] != last):
            break

    x = [1 - a for a in x[:j + 1]][::-1]

    return 1 + how_many(x, last)

t = int(raw_input())

for i in xrange(t):
    a = raw_input()
    
    b = [1 if x == '+' else 0 for x in a]

    num_flips = how_many(b, b[-1])

    if (b[-1] == 0):
        num_flips += 1

    print 'Case #%d: %d' % (i + 1, num_flips)