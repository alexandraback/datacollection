import sys
import os

def solve(T, inputs):
    ip = 0
    for t in xrange(T):
        # input variables
        N = int(inputs[ip][0])
        bff = map(lambda s: int(s)-1, inputs[ip+1])
        ip += 2

        # ls = []
        # for start in bff:
        #     used = [False] * N
        #     i = start
        #     l = 0
        #     while (used[i] == False):
        #         l += 1
        #         used[i] = True
        #         i = bff[i]
        #     ls.append(l)

        # print ls
        max_len = 0
        for start in bff:
            used = [False] * N
            # used[start] = True
            max_len = max(max_len, rec(bff, start, N, used, 0))

        print "Case #%d: %d" % (t+1, max_len)

def rec(bff, idx, N, used, cur_len):
    max_len = cur_len
    for i in xrange(N):
        if not used[i] and (bff[idx] == i or bff[i] == idx):
            used[i] = True
            max_len = max(max_len, rec(bff, i, N, used, cur_len+1))
            # used[i] = False

    return max_len


def main():
    if len(sys.argv) < 2:
        sys.exit("Usage: %s [input]" % sys.argv[0])

    if not os.path.exists(sys.argv[1]):
        sys.exit("Input file %s does not exist!" % sys.argv[1])

    with open(sys.argv[1]) as f:
        lines = f.readlines()
        T = int(lines[0])
        inputs = map(lambda l : l.strip().split(' '), lines[1:])

    solve(T, inputs)

if __name__ == "__main__":
    main()
