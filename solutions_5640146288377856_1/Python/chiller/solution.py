import math
def solve(R, C, W):
    return int(
        (W + math.ceil(float(C) / W) - 1) + (R - 1) * (C / W)
    )

if __name__ == '__main__':
    cases = input()
    for case in range(cases):
        solution = solve(*map(int, raw_input().split(" ")))
        print "Case #"+str(case+1)+": "+str(solution)