import re

#f = open(r'e:\downloads\A-large.in', 'r')
f = open(r'e:\downloads\A-small-attempt0.in', 'r')
#f = open(r'h:\work\python\code_jam\cononants.txt', 'r')


vocals = "[aeiou]"


def solve(name, n):

    def fits(s):
        return len(filter(lambda x:len(x) >= n, re.split(vocals, s))) > 0

    r = 0
    for i in range(len(name)+1):
        for j in range(i+1, len(name)+1):
            if fits(name[i:j]):
                r += 1
    return r

T = int(f.readline())
for t in range(1, T+1):
    name, n = f.readline().split()
    n = int(n)

    print "Case #%d: %d" % (t, solve(name, n))


