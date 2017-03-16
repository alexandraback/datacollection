def main():
    def get_best_score(x, surprise=False):
        if surprise:
            if x % 3 == 0:
                return (x - 3) / 3 + 2
            elif x % 3 == 1:
                return (x - 4) / 3 + 2
            elif x % 3 == 2:
                return (x - 2) / 3 + 2
        else:
            if x % 3 == 0:
                return x / 3
            elif x % 3 == 1:
                return (x - 1) / 3 + 1
            elif x % 3 == 2:
                return (x - 2) / 3 + 1
    t = int(raw_input())
    for i in range(t):
        numbers = map(int, raw_input().split(' '))
        n = numbers.pop(0)
        s = numbers.pop(0)
        p = numbers.pop(0)
        ans = 0
        numbers = sorted(numbers, key=lambda x: -x)
        for ti in numbers:
            if get_best_score(ti) >= p:
                ans += 1 
            else:
                if ti < 2 or s <= 0 or get_best_score(ti, surprise=True) < p:
                    break
                s -= 1
                ans += 1
        print "Case #%d: %d" % (i + 1, ans)

if __name__ == "__main__":
    main()
