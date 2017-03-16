T = int(input())

for c in range(1, T + 1):
    S = input().split()[1]

    standing = 0
    friends_needed = 0

    for i, Si in enumerate(int(s) for s in S):
        if i > standing:
            friends_needed += i - standing
            standing = i

        standing += Si

    print("Case #{}: {}".format(c, friends_needed))
