import sys

def fractile(k, c, s):
    if c == 1:
        return "IMPOSSIBLE" if k != s else ' '.join(map(str, [i + 1 for i in range(k)]))
    else:
        if k == 1:
            return "1"
        elif k == 2:
            return "2"
        elif k == 3:
            if s < 2:
                return "IMPOSSIBLE"
            return "2 6"
        else:
            if s < (k + 1)//2:
                return "IMPOSSIBLE"
            sol = [str(k*(k - 1))]
            for i in range(1, (k + 1)//2):
                if k & 0x1:
                    tile = (k+1)*(i*2)
                else:   
                    tile = (k+1)*(i*2 + 1)
                sol.append(str(k*k - tile + 1))
            return ' '.join(sol)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())

    for i in range(T):
        K, C, S = f.readline().strip('\n').split(" ")
        print("Case #{0}: {1}".format(i + 1, fractile(int(K), int(C), int(S))))