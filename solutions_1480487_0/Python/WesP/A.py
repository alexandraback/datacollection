import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    line = sys.stdin.readline().split()
    N, judge_scores = int(line[0]), line[1:]

    judge_scores = map(int, judge_scores)

    X = sum(judge_scores)

    work = [x for x in enumerate(judge_scores) if x[1] < X/float(N)*2 ]

#    for x in enumerate(judge_scores):
#        safe_mark = X/float(N) * 2
#        if x[1] < safe_mark:
#           pass

    work_avg = sum(x[1] for x in work) / float(len(work))
    tgt = work_avg + X/float(len(work))

    needed = ["%.5f" % 0 for x in xrange(N)]

    for x in work:
        needed[x[0]] = "%.5f" % ((tgt-x[1]) / float(X) * 100)

    print "Case #%d: %s" % (i+1, " ".join(needed))