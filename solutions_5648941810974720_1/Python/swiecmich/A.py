#ZERO
#ONE
#TWO
#THREE
#FOUR
#FIVE
#SIX
#SEVEN
#EIGHT
#NINE

t = int(raw_input())
for i in xrange(1, t + 1):
    s = raw_input()
    s = list(s)
    res = []
    while s:
        if 'Z' in s:
            res.append(0)
            for c in 'ZERO':
                s.remove(c)
        elif 'W' in s:
            res.append(2)
            for c in 'TWO':
                s.remove(c)
        elif 'U' in s:
            res.append(4)
            for c in 'FOUR':
                s.remove(c)
        elif 'X' in s:
            res.append(6)
            for c in 'SIX':
                s.remove(c)
        elif 'G' in s:
            res.append(8)
            for c in 'EIGHT':
                s.remove(c)
        elif 'S' in s:
            res.append(7)
            for c in 'SEVEN':
                s.remove(c)
        elif 'H' in s:
            res.append(3)
            for c in 'THREE':
                s.remove(c)
        elif 'F' in s:
            res.append(5)
            for c in 'FIVE':
                s.remove(c)
        elif 'O' in s:
            res.append(1)
            for c in 'ONE':
                s.remove(c)
        elif 'N' in s:
            res.append(9)
            for c in 'NINE':
                s.remove(c)
    print "Case #{}: {}".format(i, ''.join([str(d) for d in sorted(res)]))
