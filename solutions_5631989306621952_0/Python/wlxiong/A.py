import sys

def main():
    T = int(sys.stdin.readline())
    for t in range(1, T+1):
        S = sys.stdin.readline().strip()
        W = S[0]
        for c in S[1:]:
            if c >= W[0]:
                W = c + W
            else:
                W = W + c
        print "Case #%d:" % t, W

if __name__ == "__main__":
    main()
