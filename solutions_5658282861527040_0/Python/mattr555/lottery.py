cases = int(input())
for case in range(cases):
    count = 0
    a, b, k = map(int, input().split(' '))
    for i in range(a):
        for j in range(b):
            win = i & j
            if win < k:
                count += 1
    print("Case #{}: {}".format(case+1, count))
