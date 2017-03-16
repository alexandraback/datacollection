import sys
def main():
    maxn = 100005
    file = open("C-large.out", "w")
    sys.stdout = file
    mark = [True] * maxn
    prime = [0] * maxn
    ans = [0] * 10
    ansz = 0
    prisz = 0
    def chang(a, root):
        ans, r = 0, 1
        while a:
            if a & 1: ans += r
            r *= root
            a >>= 1
        return ans
    def prime_divstor(a):
        i = 0
        while i < prisz and prime[i] * prime[i] <= a:
            if a % prime[i] == 0:
                return prime[i];
            i += 1
        return False
    mark[1] = False;
    for i in range(2, maxn):
        if mark[i]:
            prime[prisz] = i;
            prisz += 1
            for j in range(i << 1, maxn, i):
                mark[j] = False;
    T = int(input());
    for test in range(1, T + 1):
        n, m = map(int, input().split())
        print("Case #" + str(test) + ":")
        a = 1 << (n - 1) | 1
        while m > 0:
            ansz = 0
            for root in range(2, 11):
                b = chang(a, root)
                t = prime_divstor(b)
                if t:
                    ans[ansz] = t
                    ansz += 1
                else:
                    break
            if ansz == 9:
                m -= 1
                print(bin(a)[2:], end = "")
                for i in range(0, 9):
                    print(" " + str(ans[i]), end = "")
                print()
            a += 2
main()