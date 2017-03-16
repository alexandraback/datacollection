def solve(a, b, k):
    counter = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                counter += 1
    return counter

for t in range(int(input())):
    a, b, k = tuple(int(s) for s in input().split())
    print("Case #" + str(t+1) + ": " + str(solve(a, b, k)))
