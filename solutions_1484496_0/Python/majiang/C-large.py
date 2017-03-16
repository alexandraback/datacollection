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

def decode(S, i, j):
    return (
      '\n' + ' '.join(str(S[k]) for k in range(len(S)) if (i>>k) & 1) +
      '\n' + ' '.join(str(S[k]) for k in range(len(S)) if (j>>k) & 1))

def solve():
    S = sorted(readints()[1:])
    indexes = {0: 0}
    # indexes[sum of the subset] = encoded subset of index
    for i in range(len(S)):
        x = S[i]
        indexes_to_add = {}
        for (s, p) in indexes.iteritems():
            ns = s + x
            np = p | (1<<i)
            if ns in indexes:
                return decode(S, indexes[ns], np)
            indexes_to_add[ns] = np
        for (s, p) in indexes_to_add.iteritems():
            indexes[s] = p

if __name__ == '__main__':
    from sys import stdin
    buf = []
    for line in stdin:
        buf.append(line)
    buf.reverse()
    N = int(buf.pop())

    for i in range(1, N+1):
        print 'Case #%d: %s' % (i, solve())
