def init():
    pass


def flip(n):
    return int(str(n)[::-1])


dp = {}


def sub_solve(n):
    if n <= 19:
        return n

    s = str(n)
    l = len(s)
    head_l = l / 2
    tail_l = l - head_l

    if int(s[head_l:]) == 0:
        return 1 + solve(n-1)

    if s[:head_l] == '1' + '0' * (head_l - 1):
        head_lp = (l-1) / 2
        tail_lp = (l-1) - head_lp
        sp = int('9' * head_lp + '0' * (tail_lp - 1) + '1')
    else:
        sp = int(s[:head_l] + '0' * (tail_l - 1) + '1')
    return (n - sp+1) + solve(flip(sp))


def solve(n):
    if n in dp:
        return dp[n]

    ans = sub_solve(n)
    dp[n] = ans
    return ans


def main():
    t = input()

    for i in range(1, t+1):
        n = input()
        print "Case #%d: %d" % (i, solve(n))


if __name__ == '__main__':
    init()

    '''print ans[N]
    exit()

    for i in range(2, N+1):
        if ans[i] < ans[i-1]:
            print '%3d: %d' % (i, ans[i])

    exit()'''

    main()