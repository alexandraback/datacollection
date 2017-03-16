import sys


f = open(sys.argv[1])
lines = f.readlines()[1:]


def output(case, result):
    print "Case #%s: %s" % (case + 1, result)


for index, line in enumerate(lines):
    K, C, S = map(int, line.strip().split())
    answer = map(str, range(1, K + 1))
    answer = " ".join(answer)
    output(index, answer)
        
    
