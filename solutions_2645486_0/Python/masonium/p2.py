import math
import sys

def read_int_list():
    x = [int(x) for x in sys.stdin.readline().strip().split()]
    return x

def solve_case():
    E, R, N = read_int_list()
    nums = read_int_list()

    if R >= E:
        return sum(nums) * E

    # we know R < E here:
    return R * sum(nums) + max(nums) * (E - R)

def main():
    num_cases = read_int_list()[0]
    for x in range(1, num_cases+1):
        print "Case #%d: %d" % (x, solve_case())

if __name__=="__main__":
    main()
