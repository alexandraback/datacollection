def better(a, b, c, d):
    if int(c) == -1: return True
    if abs(int(a) - int(b)) < abs(int(c) - int(d)):
        return True
    elif abs(int(a) - int(b)) == abs(int(c) - int(d)) and int(a) < int(c):
        return True
    elif abs(int(a) - int(b)) == abs(int(c) - int(d)) and int(a) == int(c):
        return int(b) < int(d)
    return False

T = int(raw_input())
for C in xrange(1, T+1):
    x, y = map(list, raw_input().split())
    ba, bb = -1, -1
    diff = 0
    for i in xrange(len(x)):
        if diff < 0:
            if x[i] == '?' and y[i] == '?':
                x[i] = '9'
                y[i] = '0'
            elif x[i] == '?':
                x[i] = '9'
            elif y[i] == '?':
                y[i] = '0'
        elif diff == 0:
            if x[i] == '?' and y[i] == '?':
                x[i] = '1'
                y[i] = '0'
                if better(''.join(x).replace('?', '0'), ''.join(y).replace('?', '9'), ba, bb):
                    ba, bb = ''.join(x).replace('?', '0'), ''.join(y).replace('?', '9')
                x[i] = '0'
                y[i] = '1'
                if better(''.join(x).replace('?', '9'), ''.join(y).replace('?', '0'), ba, bb):
                    ba, bb = ''.join(x).replace('?', '9'), ''.join(y).replace('?', '0')
                x[i] = '0'
                y[i] = '0'
            elif x[i] == '?':
                if y[i] != '9':
                    x[i] = chr(ord(y[i]) + 1)
                    if better(''.join(x).replace('?', '0'), ''.join(y).replace('?', '9'), ba, bb):
                        ba, bb = ''.join(x).replace('?', '0'), ''.join(y).replace('?', '9')
                if y[i] != '0':
                    x[i] = chr(ord(y[i]) - 1)
                    if better(''.join(x).replace('?', '9'), ''.join(y).replace('?', '0'), ba, bb):
                        ba, bb = ''.join(x).replace('?', '9'), ''.join(y).replace('?', '0')
                x[i] = y[i]
            elif y[i] == '?':
                if x[i] != '0':
                    y[i] = chr(ord(x[i]) - 1)
                    if better(''.join(x).replace('?', '0'), ''.join(y).replace('?', '9'), ba, bb):
                        ba, bb = ''.join(x).replace('?', '0'), ''.join(y).replace('?', '9')
                if x[i] != '9':
                    y[i] = chr(ord(x[i]) + 1)
                    if better(''.join(x).replace('?', '9'), ''.join(y).replace('?', '0'), ba, bb):
                        ba, bb = ''.join(x).replace('?', '9'), ''.join(y).replace('?', '0')
                y[i] = x[i]
            else:
                diff = cmp(ord(x[i]), ord(y[i]))
        elif diff > 0:
            if x[i] == '?' and y[i] == '?':
                x[i] = '0'
                y[i] = '9'
            elif x[i] == '?':
                x[i] = '0'
            elif y[i] == '?':
                y[i] = '9'
    if better(''.join(x), ''.join(y), ba, bb):
        ba, bb = ''.join(x), ''.join(y)
    print "Case #%d: %s %s" % (C, ba, bb)
