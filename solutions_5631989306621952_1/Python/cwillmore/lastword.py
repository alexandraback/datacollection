import sys

fp = open(sys.argv[1])
def readline():
    return fp.readline().strip()

def solve(s):
    ss = ''
    for c in s:
        ss = max(c + ss, ss + c)
    return ss

if __name__ == '__main__':
    num_cases = int(readline())
    for i in xrange(num_cases):
        s = readline()
        print "Case #%d: %s" % (i + 1, solve(s))
