import sys

sys.stdout = open('output.txt', 'w')

jp_count = []
ps_count = []
sj_count = []

def repeat(num):
    while True:
        for v in range(num):
            yield v

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def lcm(*nums):
    if len(nums) > 2:
        x, y = lcm(*nums[:-1]), nums[-1]
    else:
        x, y = nums
    return x * y // gcd(x, y)

def solve(J, P, S, K):
    global jp_count, ps_count, sj_count
    jp_count = [0] * J * P
    ps_count = [0] * P * S
    sj_count = [0] * J * S
    jps_count = [0] * J * P * S

    def pick(j, p, s):
        if (jp_count[j * P + p] >= K or
            ps_count[p * S + s] >= K or
            sj_count[j * S + s] >= K or
            jps_count[j * P * S + p * S + s] > 0):
            return None
        jp_count[j * P + p] += 1
        ps_count[p * S + s] += 1
        sj_count[j * S + s] += 1
        jps_count[j * P * S + p * S + s] = 1
        return j, p, s

    j_iter = iter(repeat(J))
    p_iter = iter(repeat(P))
    s_iter = iter(repeat(S))

    j = next(j_iter)
    p = next(p_iter)
    s = next(s_iter)

    fail_count = 0
    fail_count_max = lcm(J, P, S) * K
    while fail_count < fail_count_max:
        choice = pick(j, p, s)
        if choice is None:
            p = next(p_iter)
            choice = pick(j, p, s)
        if choice is None:
            j = next(j_iter)
            choice = pick(j, p, s)

        if choice is not None:
            yield choice
            fail_count = 0
        else:
            fail_count += 1
        s = next(s_iter)


def main():
    t = int(input())
    for i in range(t):
        ans = list(solve(*list(map(int, input().split()))))
        print('Case #{}: {}'.format(i + 1, len(ans)))
        for j, p, s in ans:
            print(j + 1, p + 1, s + 1)


main()
