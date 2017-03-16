
def cal(a, b):
    aa = list(a)
    bb = list(b)
    ans = 0
    while aa:
        ai = aa.pop(0)
        if bb[-1] < ai:
            bb.pop(0)
            ans += 1
        else:
            for i, bi in enumerate(bb):
                if bi > ai:
                    bb.remove(bi)
                    break
    return ans

def search(a, b):
    return max(cal(a, b), cal(sorted(a, reverse=True), b))

def solve():
    _ = int(raw_input())
    a = map(float, raw_input().split())
    b = map(float, raw_input().split())
    a.sort()
    b.sort()

    aa = list(a)
    bb = list(b)
    r1 = 0
    while aa:
        ai = aa.pop(0)
        if ai > bb[0]:
            r1 += 1
            bb.pop(0)
        else:
            bb.pop()

    r2 = search(a, b)
    return (r1, r2)


def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s %s' % ((i, ) + solve())

if __name__ == '__main__':
    main()
