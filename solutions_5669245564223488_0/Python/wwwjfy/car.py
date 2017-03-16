import math

for n in range(int(raw_input())):
    alpha = {}
    factor = 1
    result_set = []
    raw_input()
    items = raw_input().split(' ')
    for i in items:
        alpha.setdefault(i[0], []).append(i)
    terminate = False
    for k, v in alpha.iteritems():
        if len(v) < 2:
            alpha[k] = v[0]
            continue
        s = ''
        for i in v:
            if i[0] == i[-1]:
                if s:
                    factor += 1
                s += i
            else:
                terminate = True
                break
        if terminate:
            break
        alpha[k] = s
    if terminate:
        print('Case #%s: 0' % (n + 1, ))
        continue
    while True:
        for k, v in alpha.iteritems():
            if v[-1] in alpha and v[-1] != v[0]:
                alpha[k] = v + alpha[v[-1]]
                alpha.pop(v[-1])
                break
        else:
            break
    err = False
    if len(alpha.values()) > 1:
        if set.intersection(*[set(v) for v in alpha.values()]):
            err = True
    if err:
        print('Case #%s: 0' % (n + 1, ))
    else:
        print('Case #%s: %d' % (n + 1, math.factorial(len(alpha.values())) * math.factorial(factor)))
