from collections import deque

def main():
    for t in xrange(1, 1 + int(raw_input())):
        s = raw_input().strip()
        w = deque([s[0]])
        for x in s[1:]:
            if w[0] <= x:
                w.appendleft(x)
            else:
                w.append(x)
        print 'Case #%s: %s' % (t, ''.join(w))

main()
