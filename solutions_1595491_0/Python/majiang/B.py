def readstr():
    return buf.pop()

def readstrs():
    return buf.pop().split()

def readint():
    return int(readstr())

def readints():
    return [int(e) for e in readstrs()]

def readparam():
    'read and display'
    ans = ''
    return '\n' + ans + '\n\n'

def solve():
    'read and answer'
    dat = readints()
    n = dat[0]
    s = dat[1]
    p = dat[2]
    T = dat[3:]
    ret = 0
    for e in T:
        # corner case: 0 -> 000; 1 -> 001
        if e < 2:
            ret += p <= e
            continue
        if p <= e/3 + (e%3 > 0):
            ret += 1
            continue
        if p <= e/3 + e%3 + (e%3==0):
            if s > 0:
                s -= 1
                ret += 1
    return ret

if __name__ == '__main__':
    from sys import stdin
    buf = []
    for line in stdin:
        buf.append(line)
    buf.reverse()
    N = int(buf.pop())

    for i in range(1, N+1):
        print 'Case #%d: %s' % (i, solve())
