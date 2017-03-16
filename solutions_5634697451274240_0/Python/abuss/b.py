T = int(raw_input())

def flip(s):
    return s.replace('-','m').replace('+','-').replace('m','+')[::-1]

for i in range(T):
    s = raw_input()
    n = 0
    while s.count('+') != len(s):
        if s[0] == '+':
            p = s.index('-')
        elif '+' not in s:
            p = len(s)
        else:
            p = s.index('+')
        s = flip(s[:p]) + s[p:]
        n += 1

    print "Case #%d: %d" % (i+1, n)

