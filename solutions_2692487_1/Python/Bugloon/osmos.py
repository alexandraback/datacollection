import sys

def min_operations(A, Ns):

    added = 0
    min_ops = len(Ns)
    Ns.sort()

    while Ns:
        if Ns[0] < A:
            A += Ns.pop(0)
        elif A > 1:
            min_ops = min(min_ops, added + len(Ns))
            Ns = [A-1] + Ns
            added += 1
        else:
            return min_ops

    min_ops = min(min_ops, added)

    return min_ops 

if __name__ == "__main__":
    
    infile = sys.stdin
    outfile = sys.stdout

    T = int(sys.stdin.readline())

    for test in xrange(1, T+1):

        A, N = [int(num) for num in infile.readline().split()]
        Ns   = [int(num) for num in infile.readline().split()]

        result = min_operations(A, Ns)

        outfile.write("Case #{}: {}\n".format(test, result))
