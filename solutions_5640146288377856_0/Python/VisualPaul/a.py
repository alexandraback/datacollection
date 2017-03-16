def solve1(c, w):
    res = 0
    while c >= 2 * w:
        c -= w
        res += 1
    if c != w:
        res += 1
    res += w
    return res    
            
def solve(r, c, w):
    return solve1(c, w) + (r - 1) * (c // w)
    
ifile = open('input.txt')
ofile = open('output.txt', 'w')
t = int(ifile.readline())
for i in xrange(t):
    r, c, w = map(int, ifile.readline().split())
    print>>ofile, 'Case #{}: {}'.format(i + 1, solve(r, c, w))
ofile.close()
ifile.close()
