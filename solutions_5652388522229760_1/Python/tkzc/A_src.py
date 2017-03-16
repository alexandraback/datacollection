def check(num):
    if num == 0:
        return 'INSOMNIA'
    digits = {}
    for i in range(10):
        digits[str(i)] = 0
    timed_num = num
    while True:
        for char in str(timed_num):
            if char in digits:
                del digits[char]
        if not digits:
            return timed_num
        timed_num += num


def main():
    t = int(input())
    for i in range(t):
        num = int(input())
        print("Case #{}: {}".format(i+1, check(num)))

main()
