def main():
    t = int(raw_input())

    for j in xrange(t):
        r, c, w = [int(i) for i in raw_input().split()]
        print "Case #{}: {}".format(j+1, play(r, c, w))
        # return


def play(r, c, w):
    if w == 1:
        return r*c

    res = r*c/w
    res += w - 1
    if c % w != 0:
        res += 1

    return res


main()
