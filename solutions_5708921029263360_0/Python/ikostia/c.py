def read_input():
    j,p,s,k = map(int, raw_input().split())
    return j,p,s,k

def print_output(i, output):
    print "Case #%i: %s" % (i+1, output)

def solve(i, input):
    j,p,s,k = input
    triades = []
    for jj in xrange(1, j+1):
        for pp in xrange(1, p+1):
            for ss in xrange(1, s+1):
                triades.append((jj, pp, ss))
    
    while True:
        d = {}
        todelete = None
        for i, triade in enumerate(triades):
            if triade is None:
               continue
            t1 = (triade[0], triade[1], 0)
            t2 = (triade[0], 0, triade[2])
            t3 = (0, triade[1], triade[2])
            d[t1] = d.get(t1, 0) + 1
            d[t2] = d.get(t2, 0) + 1
            d[t3] = d.get(t3, 0) + 1
            if d[t1] > k or d[t2] > k or d[t3] > k:
                todelete = i
                break

        if todelete is None:
            break
        else:
            triades[i] = None

    triades = [('%i %i %i' % t) for t in triades if t is not None]

    res = str(len(triades)) + "\n" + "\n".join(triades)
    return res

if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        input = read_input()
        output = solve(i, input)
        print_output(i, output)

