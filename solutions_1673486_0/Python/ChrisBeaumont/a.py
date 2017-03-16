from itertools import product
from operator import mul

def total_strokes(ntype, nback, ntot):
    if nback == -1: # hit enter and start over
        return ntype + ntot + 2
    return ntot + 2 * nback + 1

def prob_correct_on_or_before(pcorr, pos):
    remaining = pcorr[:pos]
    if len(remaining) == 0:
        return 1
    return reduce(mul, remaining)

def solve(ntype, ntot, pcorr):
    pcorr = pcorr + [1] * (ntot - ntype)
    assert len(pcorr) == ntot
    expect_enter = total_strokes(ntype, -1, ntot)
    expects = [expect_enter]
    for nback in range(ntype+1):
        pos = ntype - nback
        wt = prob_correct_on_or_before(pcorr, pos)
        cost_if_right = total_strokes(ntype, nback, ntot)
        cost_if_wrong = cost_if_right + ntot + 1
        expects.append(wt * cost_if_right + (1 - wt) * cost_if_wrong)
    return min([e - ntype for e in expects])

def main():
    import sys
    file = sys.argv[1]
    data = open(file + '.in').readlines()
    with open(file+'.out','w') as out:
        ntest= int(data[0].strip())
        data = data[1:]
        for i in range(ntest):
            ntyp, ntot = map(int, data[2 * i].strip().split())
            probs = map(float, data[2 * i + 1].strip().split())
            answer = solve(ntyp, ntot, probs)
            astr = "Case #%i: %f" % (i+1, answer)
            print astr
            out.write(astr + '\n')

if __name__ == "__main__":
    main()