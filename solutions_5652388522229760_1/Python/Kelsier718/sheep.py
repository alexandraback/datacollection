t = int(input())
for i in range(1, t + 1):
    n = int(input())
    if n != 0:
        digits = [l for l in range(10)]
        num = 0
        while digits:
            num = num + n
            for d in [int(k) for k in str(num)]:
                if d in digits:
                    digits.remove(d)
        print("Case #{}: {}".format(i, num))
    else:
        print("Case #{}: INSOMNIA".format(i))
