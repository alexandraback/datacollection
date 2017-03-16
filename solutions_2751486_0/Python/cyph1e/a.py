def dumb(name, n):
    vowels = set(['a', 'e', 'i', 'o', 'u'])
    l = len(name)
    cnt = 0
    for i in range(l):
        for j in range(i + 1):
            cur = 0
            for k in range(j, i + 1):
                if name[k] in vowels:
                    cur = 0
                else:
                    cur += 1
                if cur == n:
                    cnt += 1
                    break
    return cnt

def main():
    T = int(input())
    for t in range(T):
        name, n = input().split()
        n = int(n)
        cnt = dumb(name, n)
        print('Case #{}: {}'.format(t + 1, cnt))


if __name__ == '__main__':
    main()
