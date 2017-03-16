from progressbar import *

PB_WIDGETS = [Percentage(), ' | ', SimpleProgress(), ' ', Bar(), ' ', Timer(), ' ', ETA()]


def solve(b, m):
    if m > 2 ** (b - 2):
        return "IMPOSSIBLE"

    output = "POSSIBLE\n"

    m = m - 1
    first = bin(m)[2:] + "1"
    first = "0" * (b - len(first)) + first
    output += first + "\n"

    for i in xrange(1, b):
        output += "0" * (i + 1) + "1" * (b-i-1) + "\n"
    return output.strip()

with open("q2.in") as fin:
    T = int(fin.readline())
    output = ""
    pb = ProgressBar(widgets=PB_WIDGETS, maxval=T, fd=sys.stdout).start()
    for t in xrange(T):
        pb.update(t)
        print  # pycharm fix
        b, m = map(int, fin.readline().split())
        output += "Case #%d: %s\n" % (t+1, solve(b, m))
    with open('q2.out', 'w') as fout:
        fout.write(output)
