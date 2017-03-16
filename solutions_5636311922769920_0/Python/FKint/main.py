import sys

T = int(sys.stdin.readline())
for case_nb in range(1, T+1):
    K, C, S = map(int, sys.stdin.readline().split())
    print("Case #{}: ".format(case_nb), end="")
    if K > C*S:
        print("IMPOSSIBLE")
    else:
        i = 0
        positions = []
        while i < K:
            num = 1
            for k in range(C):
                new_num = num + (K**k)*i
                i += 1
                if new_num > K**C:
                    break
                num = new_num
            positions.append(str(num))
        print(" ".join(positions))

