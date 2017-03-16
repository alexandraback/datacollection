def main():
    t = int(raw_input())
    for ti in xrange(t):
        k, c, s = map(int, raw_input().split(" "))
        req = (k-1) / c + 1
        if s < req:
            ans = "IMPOSSIBLE"
        else:
            chosen = set([])
            curr = 0
            while curr < k:
                pos = 0
                for i in xrange(c):
                    pos = pos * k
                    if curr < k:
                        pos += curr
                    curr += 1
                chosen.add(pos)
            ans = ' '.join(str(i + 1) for i in chosen)
        print "Case #%d: %s" % (ti + 1, ans)

if __name__ == "__main__":
    main()
