t = input()

def tim(dig):
    if len(dig) == 1:
        return int(dig[0])
    o = 0
    ld = len(dig)
    w = len(dig) // 2 + len(dig) % 2
    if dig[w:] == ['0'] * (ld - w):
        dig = int(''.join(dig))
        dig -= 1
        dig = list(str(dig))
        o += 1
    if len(dig) == 1:
        return o + int(dig[0])

    start, st = count_to(len(dig) - 1)
    # at most one flip try both
    sn = int(''.join(start))
    t1 = int(''.join(dig)) - sn
    t2 = float('inf')
    # reverse time
    # 10001 -> 3
    # 100001 -> 3
    w = len(dig) // 2 + len(dig) % 2
    rev_goal = dig[:w]
    rev_goal = rev_goal[::-1]
    head = ['1'] + ['0'] * (len(dig) - w - 1)
    ##print head + rev_goal, start
    rtime = int(''.join(head + rev_goal)) - int(''.join(start))
    # start from here
    rs = head + rev_goal
    rs = rs[::-1]
    rtime += 1
    ##print rs
    ##print 'rt', rtime
    t2 = int(''.join(dig)) - int(''.join(rs)) + rtime
    ##print t2
    #print st, rs, t2
    return o + min(t1 + st, t2 + st)

def lay1(dig):
    r = dig[::-1]


def count_to(le):
    if le == 1:
        return ['9'], 9
    # for odd,l middle is 9
    # for even, all but middle
    dig, time = count_to(le - 1)
    #print dig, time
    if le % 2 == 1:
        goal = ['1'] + ['0'] * (le - (le // 2 + 2) ) + ['9'] * (le // 2 + 1)
        #print 'go o', goal
        diff = int(''.join(goal)) - int(''.join(dig))
        #print diff
        return goal[::-1], time + diff + 1
    else:
        goal = ['1'] + ['0'] * (le - (le // 2 + 1) ) + ['9'] * (le // 2)
        #print 'go e', goal
        diff = int(''.join(goal)) - int(''.join(dig))
        #print diff
        return goal[::-1], time + diff + 1

for o in xrange(1, t+1):
    dig = list(raw_input())
    #print 'Case #%d:' % o
    print 'Case #%d: %d' % (o, tim(dig))

