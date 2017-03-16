import sys

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in range(1, T+1):
        A, B = map(int, f.readline().split())
        prob = [float(c) for c in f.readline().split()]
        amin = B+2
        v = B+1
        x = 2*B+A+2
        for i in xrange(A+1):
            exp = x - v
            if amin > exp:
                amin = exp
            x -= 2
            if i < A:
                v *= prob[i]
        print "Case #{0}: {1}".format(t, float(amin))

if __name__ == "__main__":
    main()