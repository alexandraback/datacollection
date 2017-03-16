from collections import deque

def the_last_word():
    res = deque()
    S = raw_input().strip()
    for c in S:
        if res and ord(c) >= ord(res[0]):
            res.appendleft(c)
        else:
            res.append(c)
    return "".join(res)


for case in xrange(input()):
    print 'Case #%d: %s' % (case+1, the_last_word())
