from math import ceil

def tm(c, f, x, v, k):
    t = 0.0
    for i in range(k):
        t += c / (v+i*f)
    t += x/(v+k*f)
    return t

def cookie(c, f, x, v = 2.0):
    # t(k) = c/v+c/(v+f)+...+c/(v+(k-1)*f)+x/(v+k*f)
    # t(k+1)-t(k) = x/(v+(k+1)*f) - (x-c)/(v+k*f) <= 0
    # => x*(v+k*f) - (x-c)*(v+(k+1)*f) <= 0
    # => c*v + c*k*f - (x-c)*f <= 0
    # => k <= ((x-c)*f - c*v) / (c*f)
    # t1 <= t0 => c/v+x/(v+f) <= x/v => c/(x-c) <= f/v
    k = max(0, int('%.0f' % ceil(((x-c)*f-c*v)/(c*f))))
    return tm(c, f, x, v, k)

t = int(raw_input())
for iCase in range(1, t+1):
    c, f, x = map(float, raw_input().split())
    r = cookie(c, f, x)
    print 'Case #%d: %.7f' % (iCase, r)
