debug = False

def ptime():
    if debug:
        from datetime import datetime
        print datetime.today().strftime("%H:%M:%S")

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

ptime()
MAX = 2000000+1

def recycle(n):
    s = str(n)
    for i in range(1, len(s)):
        if s[i] != '0':
            ret = int(s[i:] + s[:i])
            if ret < MAX:
                return ret
    return None

recycles = [recycle(i) for i in range(MAX)]

def get_recycles(n):
    ret = set([n])
    for i in range(8):
        n = recycles[n]
        if n is None:
            break
        ret.add(n)
    return ret

cycles = [get_recycles(i) for i in range(MAX)]

def get_recycles_range(n, b):
    c = [i for i in cycles[n] if n < i <= b]
    return len(c)

ptime()

def solve():
    'read and answer'
    a, b = readints()
    ret = 0
    for i in range(a, b):
        ret += get_recycles_range(i, b)
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
    ptime()
