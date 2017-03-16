import sys, functools, math

def jc(n, j):
    coin_n = 2**(n-1) + 1

    for i in range(j):
        test = True
        while test:
            coin = bin(coin_n)[2:]
            sol = []
            for base in range(2, 11):
                num = int(coin, base=base)
                k = -1
                limit  = int(math.sqrt(num))
                for div in range(2, limit):
                    if num % div == 0:
                        k = div
                        break
                if k == -1:
                    coin_n = coin_n + 2
                    break
                else:
                    sol.append(k)
            if len(sol) == 9:
                coin_n = coin_n + 2
                print(coin, ' '.join(map(str, sol)))
                test = False

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())

    for i in range(T):
        N, J = f.readline().strip('\n').split(" ")
        print("Case #{0}:".format(i + 1))
        jc(int(N), int(J))