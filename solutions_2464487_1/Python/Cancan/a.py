import math

def main():
    n = raw_input()
    for i in range(1, int(n)+1):
        r, t = map(int, raw_input().split())
        k = 2*r+1
        p = 4+4*r
        lx = 0
        hx = t
        while True:
            x = (lx+hx)/2
            if x==lx or x==hx:
                break
            mid = (2*x*(x+1) + k*(x+1)) 
            if mid>t:
                hx = x
            else:
                lx = x
        lx += 1
        print "Case #%d: %d" %(i, lx)

if __name__ == '__main__':
    main()
