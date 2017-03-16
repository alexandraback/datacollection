import copy
import sys
import math

sys.setrecursionlimit(10000)

def line2ints(instrm):
    args = instrm.readline().strip().split()
    return list(map(int, args))


def parse_case(instrm):
    return line2ints(instrm)
   
   
def solve_case(case):
    B, M = case
    if 2**(B-2) < M:
        return "IMPOSSIBLE"
    ret = "POSSIBLE"
    if M == 2**(B-2):
        last_col = "1"*(B-1)
    else:
        bits = "{:b}".format(M)
        assert len(bits) <= (B-2)
        last_col = "0" + "".join(reversed(bits))
        last_col += "0"*(B - 1 - len(last_col))
    
    assert len(last_col) == B-1
    for i, b in enumerate(last_col):
        row = "0"*(i+1) + "1"*(B-i-2) + b
        ret += "\n" + row
    ret += "\n" + "0"*B
    return ret

    


if __name__ == "__main__":
    instrm = open(sys.argv[1])
    ncases = int(instrm.readline().strip())
    for i in range(ncases):
        case = parse_case(instrm)
        ans = solve_case(case)
        print("Case #{}: {}".format(i+1, ans))
