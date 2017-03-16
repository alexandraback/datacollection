import sys

def main():
    T = int(sys.stdin.readline())
    for t in range(1, T+1):
        N = int(sys.stdin.readline())
        seq = [map(int, sys.stdin.readline().split()) for _ in range(2*N-1)]
        count = {}
        for s in seq:
            for h in s:
                count[h] = 1 + (count[h] if h in count else 0)
        miss = sorted(h for h, c in count.items() if c % 2 == 1)
        print "Case #%d:" % t, " ".join(map(str, miss))

if __name__ == "__main__":
    main()
