
if __name__ == "__main__":

    T = int(raw_input())
    for i in xrange(T):
        r, c, w = map(int, raw_input().split())
        ans = ((c + w - 1 ) // w)*(r-1)

        rightExtreme = c
        sizeOfBoat = w
        while rightExtreme >= 2*sizeOfBoat:
            rightExtreme -= sizeOfBoat
            ans += 1

        if rightExtreme == sizeOfBoat:
            ans += sizeOfBoat
        else:
            ans += sizeOfBoat + 1

        print "Case #%s: %s" % (i + 1, ans)

