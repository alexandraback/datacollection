import sys

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

def solve(n):
    if n == 0:
        return 'INSOMNIA'
    seen = set()
    i = 1
    while True:
        seen.update(str(n * i))
        if len(seen) == 10:
            return str(n * i)
        i += 1

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        n = int(readline())
        print "Case #%d: %s" % (i + 1, solve(n))
