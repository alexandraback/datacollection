import math
T = int(input())

for test in range(T):
    K,C,S = list(map(int,input().split()))
    required = math.ceil(K/C)
    if S >= required:
        to_test = []
        for j in range(required):
            positions = [x+j*C for x in range(C)]
            test_num = 1
            for exp in range(C):
                if positions[exp] >= K:
                    positions[exp] = 0
                test_num += positions[exp] * (K**exp)
            to_test.append(test_num)
        print("Case #" + str(test+1) + ": " + " ".join(list(map(str,to_test))))
    else:
        print("Case #" + str(test+1) + ": IMPOSSIBLE")        