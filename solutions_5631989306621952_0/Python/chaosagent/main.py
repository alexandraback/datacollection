from collections import deque

t = int(raw_input().strip())
for case in xrange(1, t + 1):
    final = raw_input().strip()
    s = deque()
    for c in final:
        if not len(s) or ord(c) >= ord(s[0]):
            s.appendleft(c)
        else:
            s.append(c)
    print 'Case #%d: %s' % (case, ''.join(s))
