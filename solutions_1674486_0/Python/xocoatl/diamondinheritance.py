import sys

def solve(N, g):
    lvs = set(range(1,N+1))
    for n in range(N):
        for gg in g[n]:
            if gg in lvs:
                lvs.remove(gg)

    for lv in lvs:
        gotfromlv = [False for n in range(N)]
        def recur(n):
            if gotfromlv[n-1]:
                return True
                
            if (n != lv):
                gotfromlv[n-1] = True
            for gg in g[n-1]:
                if recur(gg):
                    return True
            return False
        if recur(lv):
            return True
    return False 

def main():
    T = int(sys.stdin.readline())
    for t in range(1, T+1):
        N = int(sys.stdin.readline())
        g = [[] for n in range(N)]
        for n in range(N):
            line = map(int, sys.stdin.readline().split(" "))
            Mi = line[0]
            g[n] = line[1:]
        r = "Yes" if solve(N, g) else "No"
        sys.stdout.write("Case #%d: %s\n" % (t, r))

if __name__ == "__main__":
    main()
