inp = open('B-small-attempt4.in')
out = open('b.out', "w")

debug_model = False

T = int(raw_input()) if debug_model else int(inp.readline())


def solve(inpp) :
    answer = []
    index = 0
    for j in xrange(1, len(inpp)):
        if inpp[j] == '1':
            answer.append((index, j))
            index = j
    return answer

for i in xrange(T):
    qq = raw_input().split() if debug_model else inp.readline().split()
    B, M = int(qq[0]), int(qq[1])
    if M > 2 ** (B-2):
        if debug_model:
            print "Case #" + str(i+1) + ": IMPOSSIBLE"
        else:
            out.write("Case #" + str(i+1) + ": IMPOSSIBLE"+"\n")
    else:
        if debug_model:
            print "Case #" + str(i+1) + ": POSSIBLE"
        else:
            out.write("Case #" + str(i+1) + ": POSSIBLE" + '\n')
        s = set()


        for j in xrange(M):
            tmps = "{0:b}".format(j)
            while len(tmps) < B-2:
                tmps = '0' + tmps
            if B-2 == 0:
                tmps = ''
            tmps = '1' + tmps + '1'

            ss = solve(tmps)
            for c in ss:
                s.add(c)

        answer = []
        for j in xrange(B):
            tmpans = ''
            for qq in xrange(B):
                if (j, qq) in s:
                    tmpans += '1'
                else:
                    tmpans += '0'
            if debug_model:
                print  tmpans
            else:
                out.write(tmpans + '\n')