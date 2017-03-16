def main():
    T = int(input())
    for t in range(T):
        x, y = map(int, input().split())
        res = ""
        if y < 0: res += "NS" * (-y)
        if y > 0: res += "SN" * y

        if x < 0: res += "EW" * (-x)
        if x > 0: res += "WE" * x

        print('Case #{}: {}'.format(t + 1, res))


if __name__ == '__main__':
    main()
