def is_con(x):
    return x not in 'aeiou'

def cal_n_val(s, n):
    k = len(s)
    cnt = set()
    for i in xrange(k + 1 - n):
        if all(is_con(x) for x in s[i:i + n]):
            for l in xrange(i+1):
                for r in xrange(i+n, k+1):
                    cnt.add((l,r))
    return len(cnt)

def main():
    tot = int(raw_input())
    for t in xrange(tot):
        s, n = raw_input().split()
        n = int(n)
        print 'Case #%d: %d'%(t + 1, cal_n_val(s, n))

main()
