import sys


if __name__ == '__main__':
    fileName = sys.argv[1]
    with open(fileName + '.in') as data:
        testCase = int(data.readline().strip())
        succ = [0.0]*100010
        succ[0] = 1.0
        for i in range(1, testCase+1):
            A, B = [int(x) for x in data.readline().split(' ')]
            p = [float(x) for x in data.readline().split(' ')]
            for j in range(1, A+1):
                succ[j] = succ[j-1]*p[j-1]
            candidates = []
            ### enter
            candidates.append(B+2.0)
            ### continue
            p_continue = succ[A]*(B-A+1) + (1.0-succ[A])*(2*B-A+2.0)
            candidates.append(p_continue)
            ### delete n times
            for n in range(1, A+1):
                p_delete = succ[A-n] * (2*n + 1.0 + B-A) + (1-succ[A-n])*(2*n + 2.0 + B + B - A)
                candidates.append(p_delete)
            print "Case #%s: %s" % (i, min(candidates))
