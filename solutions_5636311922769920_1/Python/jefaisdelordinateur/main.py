T = int(input())

next_tile = 0
mypows = []

K = 0
C = 0
S = 0

def get_next_tile(depth):
    global mypows
    global next_tile
    global C
    depth -= 1
    start = mypows[depth] * next_tile
    next_tile += 1
    if next_tile >= K or depth == 0:
        return start
    return start + get_next_tile(depth)

for case in range(1, T + 1):
    K_, C_, S_ = input().split()
    K = int(K_)
    C = int(C_)
    S = int(S_)
    print("case #" + str(case) + ":", end="")
    if S * C < K:
        print(" IMPOSSIBLE")
    else:
        mypows = []
        for i in range(C + 1):
            mypows.append(pow(K, i))
        next_tile = 0
        while next_tile < K:
            print(" " + str(get_next_tile(C) + 1), end="")
        print("")
