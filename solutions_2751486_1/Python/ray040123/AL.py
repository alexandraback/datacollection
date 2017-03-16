def is_con(x):
    return x not in 'aeiou'

def cal_n_val(s, n):
    k = len(s)
    p = 0
    cnt = 0
    ccnt = 0
    for i in xrange(k + 1):
        if i < k and is_con(s[i]):
            ccnt += 1
        else:
            if ccnt >= n:
                while p + n <= i:
                    # print p, (k - (i - ccnt + n) + 1) 
                    cnt += k - max(p + n, i - ccnt + n) + 1
                    p += 1
            ccnt = 0
    return cnt

def main():
    tot = int(raw_input())
    for t in xrange(tot):
        s, n = raw_input().split()
        n = int(n)
        print 'Case #%d: %d'%(t + 1, cal_n_val(s, n))

main()
