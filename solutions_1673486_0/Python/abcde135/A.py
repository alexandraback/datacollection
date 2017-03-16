def write_case(n, s, f):
    f.write("Case #%i: %s\n" % (n, s))

def prob_correct(probs):
    return reduce(lambda x,y:x*y, probs, 1)

def expected(A, B, probs, bs):
    if bs < 0:
        return B + 2
    else:
        pc = prob_correct(probs[:A-bs])
        return (2*bs+B-A+1) + (1-pc)*(B+1)

def min_expected(A, B, probs):
    return min([expected(A, B, probs, k) for k in range(-1, A)])

def solve(infilename, outfilename):
    f = open(infilename)
    g = open(outfilename, 'w')

    T = int(f.readline())
    for n in range(T):
        (A, B) = [int(x) for x in f.readline().split()]
        probs = [float(x) for x in f.readline().split()]
        exp = min_expected(A, B, probs)
        write_case(n+1, "%.17f" % exp, g)

    f.close()
    g.close()

if __name__ == "__main__":
#    solve('A-sample.in', 'A-sample.out')
#    solve('A-sample-large.in', 'A-sample-large.out')
    solve('A-small-attempt1.in', 'A-small-attempt1.out')
#    solve('A-large.in', 'A-large.out')
