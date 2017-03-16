import re

all_poss = []

def main():
    for i in range(1000):
        for j in range(1000):
            all_poss.append((str(i), str(j)))
                
    T = int(raw_input())
    for i in xrange(T):
        c, j = raw_input().split()
        c = c.replace('?', '.')
        j = j.replace('?', '.')
        # print c, j
        mini = 1000000
        res = None
        length = len(c)
        for x, y in all_poss:
            if len(x) > length or len(y) > length:
                continue
            # print x, y
            if match(x.zfill(length), c) and match(y.zfill(length), j):
                diff = abs(int(x) - int(y))
                if diff < mini:
                    res = (x, y)
                    mini = diff

        output(i, str(res[0]).zfill(length), str(res[1]).zfill(length))

def output(casenum, c, j):
    print 'Case #%d: %s %s' % (casenum + 1, c, j)

d = {}

def match(s, pattern):
    if pattern not in d:
        d[pattern] = re.compile(pattern)
    return bool(d[pattern].match(s))

main()
