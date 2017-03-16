def solve(N):
    if N==0:
        return "INSOMNIA"
    d = set()
    i = 1
    while True:
        d |= set(str(i*N))
        if len(d)==10:
            return i*N
        i += 1

for t in range(input()):
    N = input()
    print "Case #%s: %s" % (t+1, solve(N))
