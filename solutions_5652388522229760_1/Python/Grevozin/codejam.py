def rline(fl):
    if fl is not None:
        return fl.readline()
    return raw_input()


def read_int_list(fl):
    return map(int, rline(fl).split())


def rint(fl):
    return int(rline(fl))


def solution(inp):
    num = rint(inp)
    if num == 0:
        return "INSOMNIA"
    digits = set(str(num))
    savenum = num
    while len(digits) != 10:
        num += savenum
        digits = digits.union(set(str(num)))
    return num

INPUT = "D:\\Downloads\\A-large.in"
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
