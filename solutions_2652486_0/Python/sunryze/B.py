import sys, re




def solve(r, n, m, k, ps):
    # pick n numbers from 2..m randomly, write on card
    # k times pick any card with P(0.5) and compute product
    # Peiling: determine which numbers are on cards
    sel = [2] * n
    def incr():
        for i in range(len(sel)):
            if sel[i] + 1 <= m:
                sel[i] += 1
                return
            else:
                sel[i] = 2
    def product(x):
        p = 1
        for i in range(len(sel)):
            if (1 << i) & x > 0:
                p *= sel[i]
        return p
        
    for i in range((m-1)**n):
        bs = [False] * k
        for picked in range(2**n):
            for j in range(k):
                if product(picked) == ps[j]:
                    bs[j] = True
        if all(bs):
            return sel
        incr()
    return sel
                
    


def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(1, total+1):
            r, n, m, k = map(int, f_in.readline().strip().split(' '))
            #ps = map(float, f_in.readline().strip().split(' '))
            print 'Case #1:'
            for j in range(1, r+1):
                ps = map(int, f_in.readline().strip().split(' '))
                ns = solve(r, n, m, k, ps)
                print ''.join([str(i) for i in ns])
            

if __name__ == "__main__":
    main(sys.argv[1])
