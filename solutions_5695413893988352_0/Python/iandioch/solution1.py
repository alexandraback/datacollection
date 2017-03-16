import sys

n = int(sys.stdin.readline())

def get_iter(a, i):
    while i < len(a) and a[i] != '?':
        i += 1
    if i == len(a):
        return [a]
    ans = []
    for j in xrange(0, 10):
        b = a[:]
        b[i] = str(j)
        ans.extend(get_iter(b, i+1)) 
    
    return ans

def get(s):
    a = list(s[0])
    b = list(s[1])
    a_ = [int(''.join(x)) for x in get_iter(a, 0)]
    b_ = [int(''.join(x)) for x in get_iter(b, 0)]


    best_diff = sys.maxint
    best_a = sys.maxint
    best_b = sys.maxint
    for i in xrange(len(a_)):
        for j in xrange(len(b_)):
            diff = abs(a_[i] - b_[j])
            if diff < best_diff:
                best_diff = diff
                best_a = a_[i]
                best_b = b_[j]
            elif diff == best_diff:
                if a_[i] < best_a:
                    best_a = a_[i]
                    best_b = b_[j]
                elif a_[i] == best_a:
                    best_b = min(best_b, b_[j])

    return best_a, best_b

for i in xrange(1, n+1):
    s = sys.stdin.readline().split()
    a, b = get(s)
    p = str(a)
    q = str(b)
    while len(p) < len(s[0]):
        p = '0' + p
    while len(q) < len(s[1]):
        q = '0' + q
    print 'Case #{}: {} {}'.format(i, p, q)
