import sys

# sys.stdin = open('a.in', 'r')
# sys.stdin = open('A-small-attempt1.in', 'r')
# sys.stdout = open('A-small-attempt1-1.out', 'w')
sys.stdin = open('A-large.in', 'r')
sys.stdout = open('A-large.out', 'w')


def rev(n):
    return int(str(n)[::-1])


# F = [i for i in range(1000001)]
#
# for i in range(1000000):
#     F[i+1] = min(F[i+1], F[i]+1)
#     F[rev(i)] = min(F[rev(i)], 1+F[i])


def solve(n):
    if n < 10:
        ans = n
    elif n % 10 == 0:
        ans = solve(n-1) + 1
    else:
        s = list(str(n)[::-1])
        s[0] = '1'
        for i in range(1, (len(s)+1)//2):
            s[i] = '0'
        pivot = int(''.join(s))
        nxt = 10 ** (len(s) - 1) - 1
        ans = min(solve(nxt) + (pivot - nxt) + (1 if pivot != rev(pivot) else 0) + n - int(''.join(s[::-1])), n)
        # print(pivot, nxt, (pivot - nxt) + (1 if pivot != rev(pivot) else 0) + n - int(''.join(s[::-1])))
    # print('solve:', n, '=', ans, '[vs]', F[n])
    return ans


# 1. 在每个数位上面，只会翻转一次？

# solve(110)

for t in range(int(input())):

    n = int(input())
    # if F[n] != solve(n):
        # print(n)
    # print('Case #%d: %d' % (t+1, F[n]))
    print('Case #%d: %d' % (t+1, solve(n)))

sys.stdin.close()
sys.stdout.close()