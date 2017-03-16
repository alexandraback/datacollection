def read_an_int(stream):
    return int(stream.readline())

def read_ints(stream):
    return map(int, stream.readline().split())

# observations:
#
# It no harm to use special minute at the beginning, then just let the diners
# eat without interruption.

def at_most_k(plates, k):
    """
    minimum minutes needed if we first split all the plates so that each plate has
    at most k pancakes
    """
    return k + sum((n-1)/k for n in plates)

def solve(plates):
    pmax = max(plates)
    return min(at_most_k(plates, k) for k in range(1, pmax+1))

def main():
    from sys import argv
    ifile = argv[1]
    ofile = ifile.rsplit('.', 1)[0] + '.out'
    with open(ofile, 'w') as ostr:
        with open(ifile, 'r') as istr:
            T = read_an_int(istr)
            for case in range(T):
                D = read_an_int(istr)
                plates = read_ints(istr)
                solution = solve(plates)
                ostr.write("Case #%d: %s\n" % (case+1, str(solution)))
main()
                
    
