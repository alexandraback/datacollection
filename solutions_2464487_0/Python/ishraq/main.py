r = 0
def calc_for(num_circles):
    global r
    res = num_circles * (2*r - 3);
    res += 2 * num_circles * (num_circles+1);
    return res;

T = int(raw_input())
for Z in xrange(T):
    r,t = map(int, raw_input().split(' '))
    s,e = 0, 1000000000000
    while s <= e:
        m = (s+e)/2;
        if calc_for(m) <= t:
            best = m;
            s = m+1;
        else:
            e = m-1;
    print "Case #" + str(Z+1) + ":", best
