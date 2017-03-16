import sys, os, math

def main(K, C, S):
    minimum = math.ceil(K / C)
    if minimum > S:
        return "IMPOSSIBLE"

    cs = [1] * (C + 1)
    for i in range(1, C+1):
        cs[i] = C * cs[i-1]

    tiles = []
    idx = 1
    depth = 0
    for k in range(1, math.ceil(K / C) * C + 1):
        idx = (idx - 1) * K + min(k, K)
        #print(k, depth, idx)
        depth += 1

        if depth == C:
            tiles.append(idx)

            idx = 1
            depth = 0

    return tiles


if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        K, C, S = [int(z) for z in in_file.readline().rstrip().split()]
        res = main(K, C, S)
        if isinstance(res, list):
            print("Case #{}: {}".format(case_idx + 1, " ".join([str(z) for z in res])))
        else:
            print("Case #{}: {}".format(case_idx + 1, res))
