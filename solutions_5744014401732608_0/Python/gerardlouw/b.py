from itertools import chain, combinations

T = int(input())
for t in range(1, T + 1):
    print("Case #%d:" % t, end=" ")
    B, M = map(int, input().split())
    for i in range(2**(B*(B-1)//2)):
        b = bin(i)[2:].zfill(B*(B-1)//2)
        m = [["0" for _ in range(B)] for _ in range(B)]
        for i in range(B):
            for j in range(i+1, B):
                m[i][j] = b[0]
                b = b[1:]
        paths = [0] * (B - 1) + [1]
        for i in reversed(range(B)):
            for j in range(i+1, B):
                if m[i][j] == "1":
                    paths[i] += paths[j]
        if paths[0] == M:
            print("POSSIBLE")
            print("\n".join("".join(r) for r in m))
            break
    else:
        print("IMPOSSIBLE")
