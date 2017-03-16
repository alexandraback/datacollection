def f(n, r, t):
  return 2*(n)*r + 2*(n-1)*(n-1) + 3*(n-1) + 1 <= t;

n_cases = int(raw_input())
for ctr in xrange(n_cases):
    r, t = [int(x) for x in raw_input().split(' ')]
    if not f(1, r, t):
        print('Case #{0}: {1}'.format(ctr+1, 0))
    else:
        lo = 1
        hi = 2
        while f(hi, r, t):
            lo *= 2
            hi *= 2
        while lo < hi:
            mid = lo + (hi - lo + 1)/2
            if not f(mid, r, t):
                hi =  mid - 1
            else:
                lo = mid
        print('Case #{0}: {1}'.format(ctr+1, lo))
