import sys
sys.setrecursionlimit(200000)


def solve(a):
    if a == 0:
        return "INSOMNIA"
    nums = set()
    k = 1
    while len(nums) < 10:
        nums.update(str(a * k))
        k += 1
    return str(k * a - a)



if __name__ == "__main__":
    f = open("A.in")

    lines = f.read().splitlines()
    interp_line = lambda x: map(int, x.split(" "))
    for idx, line in enumerate(lines[1:]):
        print "Case #%d: %s" % (1+idx, solve(int(line)))

    f.close()
