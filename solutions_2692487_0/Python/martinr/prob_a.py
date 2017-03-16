

#f = open(r'e:\downloads\A-large.in', 'r')
f = open(r'e:\downloads\A-small-attempt2.in', 'r')
#f = open(r'h:\work\python\code_jam\osmos.txt', 'r')

def solve(am, motes):
    if am == 1:
        return len(motes)
    if len(motes) == 0:
        return 0

    if motes[0] < am:
        return solve(am+motes[0], motes[1:])
    else:
        return min(solve(am+am-1, motes)+1, solve(am, motes[1:])+1)



T = int(f.readline())
for t in range(1, T+1):
    amote, n = map(int, f.readline().split())
    motes = map(int, f.readline().split())
    motes.sort()

    print "Case #%d: %d" % (t, solve(amote, motes))


