def main():
    def count(x):
        cnt = 0
        cur = str(x)
        appeared = set([cur])
        while True:
            cur = cur[1:] + cur[:1]
            intcur = int(cur)
            if cur in appeared:
                break
            appeared.add(cur)
            if cur[0] != '0' and B >= intcur and intcur > x:
                cnt += 1
        return cnt
    t = int(raw_input())
    for i in range(t):
        ans = 0
        A, B = map(int, raw_input().split(' '))
        for n in range(A, B):
            ans += count(n)
        print "Case #%d: %d" % (i + 1, ans)

if __name__ == "__main__":
    main()
