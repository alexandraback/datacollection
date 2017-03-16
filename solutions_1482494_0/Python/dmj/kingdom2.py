import sys

BIGNUM = 999999

def solve(values):
    N = len(values)
    two_stars = 0
    stars = 0
    played = 0
    ones_used = set()

    values = [[x,y] for (y,x) in values]
    values.sort()

    used = set()
    # print values
    while two_stars < N:

        if values[two_stars][0] <= stars:
            # print "playing game", two_stars, values[two_stars], "for second",
            stars += 1
            played += 1
            if values[two_stars][1] <= stars:
                stars += 1
                values[two_stars][1] = BIGNUM
            #     print "and first",
            # print "stars"
            two_stars += 1
                
        else:
            for idx in xrange(N-1, -1, -1):
                if values[idx][1] <= stars:
                    played += 1
                    stars += 1
                    values[idx][1] = BIGNUM
                    # print "playing game", idx, values[idx], "for first star"
                    break
            else:
                return None
    return played
            

def main(fp):
    import sys
    T = int(fp.readline())
    for case in xrange(1,T+1):
        N = int(fp.readline().strip())
        values = []
        for x in xrange(N):
            values.append(map(int, fp.readline().split()))
        f = solve(values)

        if f is None:
            result = "Too Bad"
        else:
            result = "%d" % f

        print "Case #%d: %s" % (case, result)

if __name__ == "__main__":
    # print solve([[0, 2], [4, 6], [0, 2], [4, 4], [8, 9]])
    import sys
    main(sys.stdin)



