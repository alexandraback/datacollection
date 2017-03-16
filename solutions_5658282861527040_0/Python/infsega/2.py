def parse(n):
    a = []
    while n >= 2:
        a.append(n % 2)
        n = n / 2
    a.append(n)
    return a

def add_to(l,a):
    r = a.copy()
    while len(r) < l:
        r = [0] + r
    return r

def test(test_num, f):
    A,B,K = (int(i) for i in f.readline().split(" "))
    A,B = min(A,B),max(A,B)
    a0 = parse(A)
    b0 = parse(B)
    k0 = parse(K)
    l = max(len(a0),len(b0),len(k0))
    a = add_to(l, a0)
    b = add_to(l, b0)
    k = add_to(l, k0)
    n = 0
    for i in range(A):
        for j in range(B):
            if (i&j) < K:
                n += 1
    print("Case #%d: %d" % (test_num, n))

def tests(f):
    t = int(f.readline())
    for i in range(t):
        test(i + 1, f)

f = open(r"B-small-attempt0.in")
#f = open(r"2in.txt")
tests(f)
