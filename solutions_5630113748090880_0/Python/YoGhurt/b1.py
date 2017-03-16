import math

def is_prime(n):
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def solve(N, x, f, res):
    i = 0
    counter = {}
    maxcount = 0
    reslist = []
    while i < (2*N - 1):
        s = f.readline().strip()
        ss = s.split(" ")
        for c in ss:
            c = int(c)
            if c not in counter.keys():
                counter[c] = 0
            counter[c] += 1
        i += 1
    print maxcount
    print counter
    for k in sorted(counter.keys()):
        if counter[k] % 2 == 1:
            reslist.append(str(k))
    res.write("Case #{}: {}\n".format((x+1), " ".join(reslist)))

def main():
    f = open("C://CodeJam/b1.in", 'r')
    res = open("C://CodeJam/b1.out", 'w')
    T = int(f.readline())
    for x in range(T):
        N = int(f.readline())
        solve(N, x, f, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
