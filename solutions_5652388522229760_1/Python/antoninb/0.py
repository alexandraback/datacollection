class GetDigits:
    def __init__(self, n):
        self.n = n

    def __iter__(self):
        return self

    def next(self):
        if self.n == 0:
            raise StopIteration
        else:
            r = self.n % 10
            self.n = self.n / 10
            return r

def find_res(N):
    s = set()
    v = N
    count = 0
    if N == 0:
        return None
    while True:
        for b in GetDigits(v):
            if b not in s:
                count += 1
                if count == 10:
                    return v
                s.add(b)
        v += N

with open("in") as f:
    T = int(f.readline())
    for t in xrange(T):
        N = int(f.readline())
        r = find_res(N)
        if r is None:
            r = "INSOMNIA"
        print "Case #{}: {}".format(t + 1, r)

