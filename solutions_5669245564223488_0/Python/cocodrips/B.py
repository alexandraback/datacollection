import itertools

def solve(N, strings):

    cnt = 0
    sset = []
    for pair in itertools.permutations(strings):
        perm = []
        next = [0]
        for i in xrange(N - 1):
            if pair[i][-1] != pair[i+1][0]:
                if len(next) > 1:
                    perm.append(next)
                    next = [i + 1]
                else:
                    break
            else:
                next.append(i + 1)
        else:
            perm.append(next)

            for pp in perm:
                if len(pp) < 2:
                    break
            else:
                cnt += 1


    return cnt







if __name__ == "__main__":
    with open('inputB.txt', 'r') as infile, open('outputB.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(line.split())

        T = int(data[0][0])
        data.pop(0)

        for t in xrange(T):
            N = int(data[0][0])
            data.pop(0)

            strings = data[0]
            data.pop(0)

            ans = solve(N, strings)
            str = "Case #{0}: {1}\n".format(t+1, ans)
            print str

            outfile.write(str)

