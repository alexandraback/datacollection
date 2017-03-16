for t in range(int(input().strip())):
    n = int(input().strip())
    if n == 0:
        print('Case #%d: INSOMNIA' % (t + 1))
        continue
    s = set(range(10))
    for i in range(1, 100):
        next = n * i
        while next > 0:
            digit = next % 10
            if digit in s:
                s.remove(digit)
            next = next // 10
        if len(s) == 0:
            print('Case #%d: %d' % (t + 1, n * i))
            break
