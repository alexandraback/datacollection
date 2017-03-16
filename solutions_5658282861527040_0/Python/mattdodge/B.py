
def out(case_num, st):
    print("Case #%d: %s" % (case_num, st))

def get_bit_counts(num, pos):
    if num > 2**(pos+1):
        return [2**pos, 2**pos]

    if num < 2**pos:
        return [num, 0]





def run_case(case_num, input):
    A, B, K = [int(x) for x in input.readline().rstrip("\n").split(" ")]

    score = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K:
                score += 1

    out(case_num, score)

# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    with sys.stdin as f:
        [run_case(i + 1, f) for i in range(int(f.readline()))]
