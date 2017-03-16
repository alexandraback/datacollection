t = int(input())
for I in range(1, t + 1):
    k, c, s = map(int, input().split())
    if k > s * c:
        ans = "IMPOSSIBLE"
    else:
        ans = []
        last = 0
        flag = True
        while flag:
            pos = 0
            for i in range(c):
                pos = pos * k + last
                if last < k - 1:
                    last += 1
                else:
                    flag = False
            ans.append(pos + 1)
        ans = " ".join(map(str, ans))
    print("Case #{}: {}".format(I, ans))



