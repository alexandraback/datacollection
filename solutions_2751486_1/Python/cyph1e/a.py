def solve(name, n):
    l = len(name)
    vowels = set(['a', 'e', 'i', 'o', 'u'])
    last = None
    cur = 0
    cnt = 0
    for i in range(l):
        if name[i] in vowels:
            cur = 0
        else:
            cur += 1
            if cur >= n:
                last = i - n + 1

        if last is not None:
            cnt += last + 1

    return cnt


def main():
    T = int(input())
    for t in range(T):
        name, n = input().split()
        n = int(n)
        cnt = solve(name, n)
        print('Case #{}: {}'.format(t + 1, cnt))


if __name__ == '__main__':
    main()
