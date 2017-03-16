task = "A-large"
infile = open('in/%s.in' % task, 'r')
outfile = open('out/%s.out' % task, 'w')
T = int(infile.readline().strip())


def solve():
    N = int(infile.readline().strip())
    if N == 0:
        return "INSOMNIA"
    digits = [str(i) for i in range(10)]
    for i in range(1000000):
        number = str((i+1) * N)
        for d in list(number):
            try:
                digits.remove(d)
            except:
                pass
        if len(digits) == 0:
            return number
    return "omg"

for case in range(1, T+1):
    outfile.write("Case #%d: %s\n" % (case, solve()))

infile.close()
outfile.close()
