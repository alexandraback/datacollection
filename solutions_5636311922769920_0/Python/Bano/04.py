import math
num = int(input())
for i in range(num):
    inp = input().split(" ")
    K = int(inp[0])
    C = int(inp[1])
    S = int(inp[2])
    ans_list = list()

    if S < K/C:
        print("Case #" + str(i+1) + ": IMPOSSIBLE")
        continue
    checked = 0
    total_length = pow(K, C)
    for j in range(math.ceil(K/C)):
        temp = total_length // K
        ans = 0
        for k in range(C):
            ans += temp * checked
            temp //= K
            checked += 1
            if checked == K:
                checked = 0
        ans_list.append(ans)
    print("Case #" + str(i+1) + ": " + " ".join([str(c+1) for c in ans_list]))

