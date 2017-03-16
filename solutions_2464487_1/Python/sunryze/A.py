import sys, re




def solve(r, t):
    def pt(i):
        return i * (2*i+2*r-1)
    def bins(l, h):
        if l + 1 >= h:
            return l if pt(h) > t else h
        m = (l + h) / 2
        if pt(m) > t:
            return bins(l, m)
        else:
            return bins(m, h)
    i = 1
    while pt(i) < t:
        i = i << 1
    return bins(0, i)



def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(1, total+1):
            a, b = map(int, f_in.readline().strip().split(' '))
            print 'Case #{0}: {1}'.format(i, solve(a, b))
            

if __name__ == "__main__":
    main(sys.argv[1])
