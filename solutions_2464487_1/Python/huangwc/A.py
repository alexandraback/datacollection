from sys import stdin, stdout

stdin = open('A-large.in', 'r')
stdout = open('A-large.out', 'w')

def my_sqrt(x):
    l = 1
    r = 1
    while(r <= x):
        r <<= 1
    while(r > l + 1):
        m = (r + l) >> 1
        if m * m <= x:
            l = m
        else:
            r = m
    return l

T = int(stdin.readline().strip())

for c in range(0, T):

    (r, t) = [int(x) for x in stdin.readline().strip().split()]

    stdout.write('Case #%d: %d\n' % \
                 (c+1, int((-r-r+1+my_sqrt((r+r-1)*(r+r-1)+8*t))//4)))


stdin.close()
stdout.close()
