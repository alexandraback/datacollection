import sys
from collections import defaultdict


def dress(A, K):
    j_p = defaultdict(int)
    j_s = defaultdict(int)
    p_s = defaultdict(int)
    ret = []
    for i in xrange(1, A[0]+1):
        for j in xrange(1, A[1]+1):
            for k in xrange(1, A[2]+1):
                j_p_i = "%d%d" % (i, j)
                p_s_i = "%d%d" % (j, k)
                j_s_i = "%d%d" % (i, k)
                if j_p[j_p_i] < K and j_s[j_s_i] < K and p_s[p_s_i] < K:
                    j_p[j_p_i] += 1
                    j_s[j_s_i] += 1
                    p_s[p_s_i] += 1
                    ret.append("%s %s %s" % (i, j, k))
    return len(ret), "\n".join(ret)


if __name__ == "__main__":
    output_file = open("%s.%s" % (sys.argv[1].split(".")[0], "out"), "w")
    file_name = sys.argv[1]
    input_file = open(file_name)
    case_count = int(input_file.readline())
    for i in xrange(case_count):
        vals = map(int, input_file.readline().strip().split())
        A = vals[0:3]
        k = vals[3]
        n, comb = dress(A, k)
        output_file.write("Case #%s: %s\n%s\n" % (i+1, n, comb))

    output_file.close()
    input_file.close()
    print "Done!"
