import sys

if __name__ == '__main__':
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)
    output = open('A.out', 'w')
    t = int(f.readline())
    for test in xrange(1, t+1):
        str1 = "Case #%d: " %(test)
        output.write(str1)
        a, b = map(int, f.readline().split())
        pr = map(float, f.readline().split())
        mini = (b+2)*1.0
        prod = 1
        for i in range(a):
            prod *= pr[i]
            exp = prod*(a+b-2*i-1)+(1-prod)*(a+2*b-2*i)
            if exp < mini:
                mini = exp
        ans = "%.6f"%(mini)
        output.write(ans+"\n")
    output.close()
