from multiprocessing import Pool  
import sys
import time

def solve(data):
    (N,S) = data
    X = sum(S)

    results = []
    for index,ji in enumerate(S):
        ls = [x for x in S]
        del ls[index]
        yyi = []
        for jj in ls:
            jj = min(ls)
            yi = float(jj-ji+X)/(2*X)
            yi = float(1/N)+1-float(ji)/X
            yi = (float(X*(N+1))/N-ji)/X
            yi = (float(2*X)/N-ji)/X
#            print "%f %f"%(ji+ X*yi, jj+X*(1-yi))
            yyi.append(yi)

        results.append("%f"%(100*min(yyi)))

    solution = " ".join(results)
    return solution


def loadTests(filename):
    tests = []

    f = open(filename)

    # read the number of tests
    T = int(f.readline())

    for i in range(T):
        l = map(int, f.readline().strip().split(" "))
        tests.append([l[0],l[1:]])

    return tests




if __name__ == "__main__":

    if len(sys.argv) != 2:
        print "usage: %s datafile"%(sys.argv[0])
        sys.exit(1)


    multi = False

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
        print "Case #%d: %s"%(index+1,result)

    printed = time.time()

    # sys.stderr.write("Operation\tTime\t\tTotal time\n")
    # sys.stderr.write("Loading:\t%8.5fs\t%8.5fs\n"%(loaded-start, loaded-start))
    # sys.stderr.write("Solving:\t%8.5fs\t%8.5fs\n"%(solved-loaded, solved-start))
    # sys.stderr.write("Printing:\t%8.5fs\t%8.5fs\n"%(printed-solved, printed-start))


