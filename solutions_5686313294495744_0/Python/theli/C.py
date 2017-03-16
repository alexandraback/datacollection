from sys import stdin
from itertools import product

T = int(stdin.readline())

for case in xrange(1,T+1):
    n_TOPICS = int(stdin.readline())
    topics = []
    for _ in xrange(n_TOPICS):
        topics.append(stdin.readline().strip().split(' '))
    f,s = zip(*topics)
    # result = 0
    # for i in xrange(n_TOPICS):
        # nf = f.count(f[i]) - 1
        # ns = s.count(s[i]) - 1
        # result += min(1, nf * ns)
    f_c = set(f)
    s_c = set(s)
    # m = max(f_c, s_c)
    # result = n_TOPICS - m
    result = n_TOPICS
    unused = set(range(n_TOPICS))
    while len(s_c) > 0 or len(f_c) > 0:
        # print result, s_c, f_c
        if len(s_c) == 0:
            result -= len(f_c)
            break
        elif len(f_c) == 0:
            result -= len(s_c)
            break
        else:
            s_ = s_c.pop()
            lasti = None
            for i in unused:
                if s[i] == s_:
                    lasti = i
                    if f[i] in f_c:
                        f_c.remove(f[i])
                        break
            unused.remove(lasti)
            result -= 1

    result2 = n_TOPICS
    f_c = set(f)
    s_c = set(s)
    unused = set(range(n_TOPICS))
    while len(s_c) > 0 or len(f_c) > 0:
        # print result, s_c, f_c
        if len(s_c) == 0:
            result2 -= len(f_c)
            break
        elif len(f_c) == 0:
            result2 -= len(s_c)
            break
        else:
            s_ = f_c.pop()
            lasti = None
            for i in unused:
                if f[i] == s_:
                    lasti = i
                    if s[i] in s_c:
                        s_c.remove(s[i])
                        break
            unused.remove(lasti)
            result2 -= 1

    result = max(result,result2)


    print 'Case #{0}: {1}'.format(case, result)

