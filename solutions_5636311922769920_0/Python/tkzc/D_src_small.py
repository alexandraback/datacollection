def main():
    t = int(input())
    for i in range(t):
        k, c, s = [int(tmp) for tmp in input().split(' ')]
        res = list(range(1, pow(k, c) + 1, pow(k, c - 1)))
        print("Case #{}: {}".format(i+1, ' '.join(map(str, res))))

if __name__ == '__main__':
    main()
