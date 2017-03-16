def odd(n):
    return n*(4*n*n-1)/3

def even(n):
    return 2*n*(n+1)*(2*n+1)/3

if __name__ == '__main__':
    T = input()
    for cas in xrange(T):
        r, t = map(int, raw_input().split())
        ans, res, sum1, sum2 = 0, 0, 0, 0
        mid, low, high = 1, 1, t
        st = r/2-1 if r % 2 == 0 else r/2
        while low < high:
            mid = (low+high)/2
            if r % 2 == 0:
                sum1 = even(mid+st) - even(st)
                sum2 = odd(mid+st+1) - odd(st+1)
                res = sum2 - sum1
            else:
                sum1 = even(mid+st) - even(st)
                sum2 = odd(mid+st) - odd(st)
                res = sum1 - sum2
            if res == t:
                ans = mid
                break
            if res > t: high = mid
            else:
                ans = mid
                low = mid + 1
        print 'Case #{0}: {1}'.format(cas+1, ans)

