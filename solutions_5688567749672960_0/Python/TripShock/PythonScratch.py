def optimal_flip(cur, steps, N):
    digits = len(str(cur))
    places = 1
    flipped = cur
    for _ in range(digits // 2):
        add = places * 9

        while add > 0:
            temp = int(str(flipped + add)[::-1])
            if temp <= N:
                break
            add -= places

        flipped += add
        places *= 10

    if flipped != cur:
        steps += flipped - cur
        temp = int(str(flipped)[::-1])
        if temp != flipped:
            flipped = temp
            steps += 1

    return flipped, steps


def optimal_advance(cur, steps, N):
    digits = len(str(cur))
    largest = 10 ** digits

    steps = steps + min(largest, N) - cur
    cur = min(largest, N)

    return cur, steps


T = int(input())

for c in range(1, T + 1):
    N = int(input())

    cur = 1
    steps = 1

    while cur != N:

        cur, steps = optimal_flip(cur, steps, N)
        # print("{}({}) - ".format(cur, steps), end='')
        cur, steps = optimal_advance(cur, steps, N)
        # print("{}({})".format(cur, steps))

    print("Case #{}: {}".format(c, steps))
