def main():
    T = int(input())
    for i in range(T):
        K, C, S = map(int, input().split())
        if S < (K + C - 1) // C:
            print('Case #%d: IMPOSSIBLE' % (i + 1))
        else:
            result = 'Case #%d:' % (i + 1)
            for j in range((K + C - 1) // C):
                t = j * C
                if t + C - 1 >= K:
                    t = K - C
                x = 0
                for k in range(C):
                    if t + k > 0:
                        x = x * K + t + k
                result += ' %d' % (x + 1)
            print(result)


if __name__ == "__main__":
    main()
