def solve(n):
    if n == 0:
        return 'INSOMNIA'
    count = 0
    nums = [False] * 10
    for i in range(1, 200):
        m = n * i
        while m != 0:
            digit = m % 10
            if not nums[digit]:
                nums[digit] = True
                count += 1
            m //= 10
        if count == 10:
            return n * i

T = int(input())
for t in range(T):
    n = int(input())
    print('Case #{}: {}'.format(t + 1, solve(n)))
