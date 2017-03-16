import sys

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

def solve(s):
    result = 0
    for i in xrange(len(s) - 1):
        if s[i] != s[i + 1]:
            result += 1
    if s[-1] == '-':
        result += 1
    return result

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        s = readline()
        print "Case #%d: %s" % (i + 1, solve(s))
