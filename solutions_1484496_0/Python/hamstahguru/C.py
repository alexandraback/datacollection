from multiprocessing import Pool  
import sys
import time

def subsets(mySet):
    return reduce(lambda z, x: z + [y + [x] for y in z], mySet, [[]])

def solve(data):
    S = set(data)
    sums = {}
    sub = subsets(S)
    result = None
    for s in sub:
        sm = sum(s)
        if sm in sums:
            result = (sums[sm], s)
            break
        else:
            sums[sm] = s

    if not result:
        return "Impossible"
    else:
        return "%s\n%s"%(" ".join(map(str, result[0])), " ".join(map(str, result[1])))


def loadTests(filename):
    tests = []

    f = open(filename)

    # read the number of tests
    T = int(f.readline())

    for i in range(T):
        l = map(int, f.readline().strip().split(" "))
        tests.append(l[1:])

    return tests




if __name__ == "__main__":

    if len(sys.argv) != 2:
        print "usage: %s datafile"%(sys.argv[0])
        sys.exit(1)


    multi = True

    start = time.time()

    tests = loadTests(sys.argv[1])

    loaded = time.time()

    if multi:
        pool = Pool()
        results = pool.map(solve,tests)

    else:
        results = [ solve(test) for test in tests ]

    solved = time.time()

    for index,test in enumerate(tests):
        result = solve(test)
        print "Case #%d:\n%s"%(index+1,result)

    printed = time.time()

    sys.stderr.write("Operation\tTime\t\tTotal time\n")
    sys.stderr.write("Loading:\t%8.5fs\t%8.5fs\n"%(loaded-start, loaded-start))
    sys.stderr.write("Solving:\t%8.5fs\t%8.5fs\n"%(solved-loaded, solved-start))
    sys.stderr.write("Printing:\t%8.5fs\t%8.5fs\n"%(printed-solved, printed-start))


