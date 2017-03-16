for case in range(int(input())):

    r, c, w = map(int, str.split(input()))
    count = c // w * r + (1 if c % w else 0) + w - 1
    print(str.format("Case #{}: {}", case + 1, count))
