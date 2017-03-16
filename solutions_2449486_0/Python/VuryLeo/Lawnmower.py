import sys

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        h, w = tuple(map(int, sys.stdin.readline().split()))
        aimlawn = [list(map(int, sys.stdin.readline().split())) for i in range(h)]
        lawn = [[100 for i in range(w)] for j in range(h)]
        for i in range(h):
            mow = max(aimlawn[i])
            lawn[i] = [min(grass, mow) for grass in lawn[i]]
        for i in range(w):
            mow = max([aimlawn[j][i] for j in range(h)])
            for j in range(h):
                lawn[j][i] = min(lawn[j][i], mow)
        if lawn == aimlawn:
            sys.stdout.write("YES\n")
        else:
            sys.stdout.write("NO\n")

