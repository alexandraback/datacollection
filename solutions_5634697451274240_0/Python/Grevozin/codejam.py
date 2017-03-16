def rline(fl):
    if fl is not None:
        return fl.readline()
    return raw_input()


def read_int_list(fl):
    return map(int, rline(fl).split())


def rint(fl):
    return int(rline(fl))


def solution(inp):
    string = rline(inp)[:-1] + "+"
    symb = string[0]
    ans = 0
    for currsymb in string[1:]:
        if symb != currsymb:
            ans += 1
            symb = currsymb
    return ans

INPUT = "D:\\Downloads\\B-small-attempt0.in"
OUTPUT = "output.txt"
try:
    f = open(INPUT)
except IOError:
    f = None
out = open(OUTPUT, "w")
n = rint(f)
for i in xrange(n):
    out.write(u"Case #{0}: {1}\n".format(i + 1, solution(f)))
if f is not None:
    f.close()
out.close()
