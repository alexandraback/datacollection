def is_possible(k, c, s):
    return c*s >= k

def find_tile(k, c, f):
    tile = 0
    for i in xrange(c):
        tile = tile*k + f + i
    return tile

def clean_tiles(k, c, s):
    if not is_possible(k, c, s):
        return "IMPOSSIBLE"
    num_tiles = (k/c)
    to_clean = []
    d = c-1
    for i in xrange(num_tiles):
        to_clean.append(str(find_tile(k, c, c*i)+1))
    if k%c != 0:
        to_clean.append(str(find_tile(k, c, k-k%c) - find_tile(k, c-k%c, k)+1))
    return ' '.join(to_clean)

def main():
    t = int(raw_input())
    for i in xrange(t):
        k, c, s = map(int, raw_input().strip().split())
        print "Case #{}: {}".format(i+1, clean_tiles(k, c, s))

if __name__ == '__main__':
    main()

"""

k*(1) + 2

# k = 5, c = 4
k*k*(1) + k*(2) + 3

d = c-1
\sum_{i=1}^{i=d} k^(d-i)*i + 1

(1-2-3-4)-5-6-7-8
k^(3)*0 + k^(2)*1 + k^(1)*2 + k^(0)*3

1-2-3
k^(1)*1 + k^(0)*2


1-2-3-4-(5-6-7-8)
k^(3)*4 + k^(2)*5 + k^(1)*6 + k^(0)*7

d = c-1 = 4-1 = 3, i = 4
k^(d-j)*(j+i)
k^(3)*4 + k^(2)*5 + k^(1)*6 + k^(0)*7

1-2-3-4-5-6-7-8-(9-10)
k^(3)*8 + k^(2)*9 + k^(1)*10 + k^(0)*11 - (k^(1)*10 + k^(0)*11)

k=3, c=2, d=1

k^(1)*(f) + k^(0)*(f+1)

def find_tile(k, c, f):
    if k <= 1:
        return 0
    if c == 1:
        return f
    d = c-1
    numer = (f*(k-1)*(k**(d+1)-1)) + (k*(k**d-1)) - (d*k) + (d)
    denom = (k-1)**2
    assert numer % denom == 0
    return numer / denom

"""
