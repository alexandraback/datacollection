def find():
    magic = []
    def check(n):
        n2 = n*n
        s2 = str(n2)
        if s2 == s2[::-1]:
            magic.append(int(s2))
    for i in range(1, 10):
        check(i)
    for i in range(1, 10000):
        s = str(i)
        n = int(s + s[::-1])
        check(n)
        for d in range(10):
            check(int('%s%d%s' % (s, d, s[::-1])))
    return sorted(magic)
        
def solve(magic):
    A, B = map(int, raw_input().split())
    ct = 0
    for m in magic:
        if A <= m <= B:
            ct += 1
    return ct

def main():
    magic = find()
    T = int(raw_input())
    for t in range(T):
        print 'Case #%d: %d' % (t+1, solve(magic))

if __name__ == '__main__':
    main()
    