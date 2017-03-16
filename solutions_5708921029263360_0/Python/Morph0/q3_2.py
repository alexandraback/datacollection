from progressbar import *
from collections import defaultdict
import itertools

PB_WIDGETS = [Percentage(), ' | ', SimpleProgress(), ' ', Bar(), ' ', Timer(), ' ', ETA()]


def solve(j, p, s, k):
    outputs = set()
    counts = defaultdict(lambda: 0)
    counts[(1, 1, 1)] = 0

    def iter_possible_outputs():
        for nj, np, ns in itertools.product(range(1, j+1), range(1, p+1), range(1, s+1)):
            if (nj, np, ns) not in outputs:
                yield (nj, np, ns)

    while max(counts.itervalues()) <= k:
        try:
            next_move = min(iter_possible_outputs(), key=lambda possible_move: max(
                    counts[(None, possible_move[1], possible_move[2])],
                    counts[(possible_move[0], None, possible_move[2])],
                    counts[(possible_move[0], possible_move[1], None)],
                )
            )
        except ValueError:
            break

        counts[(None, next_move[1], next_move[2])] += 1
        counts[(next_move[0], None, next_move[2])] += 1
        counts[(next_move[0], next_move[1], None)] += 1

        if max(counts.itervalues()) <= k:
            outputs.add(next_move)

    out = str(len(outputs)) + "\n"

    for output in outputs:
        out += " ".join(map(str, output)) + "\n"

    return out.strip()

with open("q3.in") as fin:
    T = int(fin.readline())
    output = ""
    pb = ProgressBar(widgets=PB_WIDGETS, maxval=T, fd=sys.stdout).start()
    for t in xrange(T):
        pb.update(t)
        print  # pycharm fix
        j, p, s, k = map(int, fin.readline().split())
        output += "Case #%d: %s\n" % (t+1, solve(j, p, s, k))
    with open('q3.out', 'w') as fout:
        fout.write(output)