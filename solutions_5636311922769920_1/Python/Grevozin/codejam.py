def rline(fl):
    if fl is not None:
        return fl.readline()
    return raw_input()


def read_int_list(fl):
    return map(int, rline(fl).split())


def rint(fl):
    return int(rline(fl))


def solution(inp):
    k, c, s = map(int, rline(inp).split())
    if c * s < k:
        return "IMPOSSIBLE"
    digits = range(k)
    numbers = []
    cnt = 0
    while cnt < k:
        numbers.append(digits[cnt:cnt+c])
        cnt += c
    result = []
    for num in numbers:
        ans = 0
        kpower = 1
        for digit in num:
            ans += kpower * digit
            kpower *= k
        result.append(ans)
    return " ".join(map(lambda j: str(j+1), result))

INPUT = "D:\\Downloads\\D-large.in"
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
