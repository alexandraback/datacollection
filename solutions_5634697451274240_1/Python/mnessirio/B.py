task = "B-large"
infile = open('in/%s.in' % task, 'r')
outfile = open('out/%s.out' % task, 'w')
T = int(infile.readline())


def solve():
    S = infile.readline().strip()
    simple_S = S[0]
    for l in list(S):
        if l != simple_S[-1]:
            simple_S += l
    if simple_S[-1] == '+':
        return len(simple_S) - 1
    return len(simple_S)


for case in range(1, T+1):
    outfile.write("Case #%d: %s\n" % (case, solve()))

infile.close()
outfile.close()
