import sys

def f(x):
    y = x
    s = set(str(x))
    while len(s) < 10:
            y += x
            s = s.union(set(str(y)))
    return y

if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]
    Nv = map(int, inp)

    outp = open(r"out.txt", "wb")
    for i in xrange(len(Nv)):
        N = Nv[i]
        if N == 0:
            r = "INSOMNIA"
        else:
            r = str(f(N))
        outp.write("Case #%d: " % (i+1) + r + "\r\n")
    outp.close()
