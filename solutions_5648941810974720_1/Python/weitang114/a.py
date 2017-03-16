import numpy as np

def run(s):
    let = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    s = (list(s))
    a = []
    def do(n, s, l):
        l.append(n)
        for c in let[n]:
            s.remove(c)
        return s, l
    lastlen = 0 
    while len(s) != lastlen:
        lastlen = len(s)

        if 'Z' in s:
            s, a = do(0, s, a)
        if 'X' in s:
            s, a = do(6, s, a)
        if 'G' in s:
            s, a = do(8, s, a)
        if 'U' in s: 
            s, a = do(4, s, a)
        if 'W' in s: 
            s, a = do(2, s, a)
    lastlen = 0
    while len(s) != lastlen:
        lastlen = len(s)

        if 'O' in s:
            s, a = do(1, s, a)
        if 'R' in s:
            s, a = do(3, s, a)
        if 'F' in s:
            s, a = do(5, s, a)

    lastlen = 0
    while len(s) != lastlen:
        lastlen = len(s)
        if 'V' in s:
            s, a = do(7, s, a)

    lastlen = 0
    while len(s) != lastlen:
        lastlen = len(s)
        if 'N' in s:
            s, a = do(9, s, a)

    return sorted(a)


def main():
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        m = raw_input() # read a list of integers, 2 in this case
        
        
        res = run(m)

        print "Case #{}: {}".format(i, ''.join(map(str, res)))
        # check out .format's specification for more formatting options

main()
