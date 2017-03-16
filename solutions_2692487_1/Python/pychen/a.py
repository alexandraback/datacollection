# source code for GCJ2013 round 1B
# by Pengyu CHEN(cpy.prefers.you@gmail.com)
# COPYLEFT, ALL WRONGS RESERVED.

def main():
    T = int(input())
    for t in range(T):
        A, N = list(map(int, input().split()))
        sz = list(map(int, input().split()))
        sz = sorted(sz)
        while sz and sz[0] < A:
            A += sz[0]
            sz = sz[1:]
        ans = len(sz)
        mov = 0
        while sz and N:
            N -= 1
            mov += 1
            A += A - 1
            while sz and sz[0] < A:
                A += sz[0]
                sz = sz[1:]
            if mov + len(sz) < ans:
                ans = mov + len(sz)
        print("Case #%d: %s" %(t + 1, ans))
    pass

if __name__ == "__main__":
    main()
