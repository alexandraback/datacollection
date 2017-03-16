import difflib, collections, math

def solve(p, q):

    # print math.log(q, 2)

    c = 1
    while 2 * p < q:
        if q % 2 == 0:
            q //= 2
        else:
            return -1
        c +=1

    for i in xrange(1, 10):
        if 1 << i == q:
            return c

    print p, '/', q, c
    return -1

    # current = [(0, 1), (1, 1)]
    # k = 0
    # while k < 6:
    #     print current
    #     k += 1
    #     print k
    #     new = []
    #
    #     for i in xrange(len(current)):
    #         for j in xrange(len(current)):
    #             if i == j :
    #                 continue
    #             pi, qi = current[i]
    #             pj, qj = current[j]
    #             ss = (pi * qj + pj * qi, qi*qj * 2)
    #             if p * ss[1] == q * ss[0]:
    #                 return k
    #             new.append(ss)
    #     current += new
    #     current = list(set(current))

    return -1



if __name__ == "__main__":
    with open('inputA.txt', 'r') as infile, open('outputA.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(line.split())

        T = int(data[0][0])
        data.pop(0)

        for t in xrange(T):
            p, q = map(int, data[0][0].split('/'))
            data.pop(0)
            ans = solve(p, q)
            if ans < 0:
                str = "Case #{0}: {1}\n".format(t+1, 'impossible')
            else:
                str = "Case #{0}: {1}\n".format(t+1, ans)

            outfile.write(str)


