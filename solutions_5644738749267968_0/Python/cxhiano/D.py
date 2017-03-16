if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        n = int(raw_input())
        a = sorted(map(float, raw_input().split()))
        b = sorted(map(float, raw_input().split()))

        tmp = b[:]
        ans_1 = 0
        for x in a:
            if x > b[0]:
                ans_1 += 1
                b = b[1:]
            else:
                b = b[:-1]

        ans_2 = 0
        b = tmp[:]
        for x in a:
            ans_2 += 1
            for y in b:
                if y > x:
                    b.remove(y)
                    ans_2 -= 1
                    break

        print 'Case #{0}: {1} {2}'.format(t + 1, ans_1, ans_2)
