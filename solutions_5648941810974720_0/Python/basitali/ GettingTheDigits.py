def findnumber(inp):
    values = [("Z", "ZERO", "0"),
    ("W", "TWO", "2"),
    ("U", "FOUR", "4"),
    ("X", "SIX", "6"),
    ("O", "ONE", "1"),
    ("G", "EIGHT", "8"),
    ("R", "THREE", "3"),
    ("F", "FIVE", "5"),
    ("V", "SEVEN", "7"),
    ("N", "NINE", "9")]

    number = ""
    remaining_inp = list(inp)
    while len(remaining_inp) > 0:
        for v in values:
            if v[0] in remaining_inp:
                number += v[2]
                for x in v[1]:
                    remaining_inp.pop( remaining_inp.index(x) )
                break

    return "".join(sorted(number))

if __name__ == '__main__':
    case = 'A-sample'
    case = 'A-small-attempt0'
    inp = open('%s.in'%case)
    out = open('%s.out'%case, 'w')

    cases = int(inp.readline())
    for i in xrange(1, cases + 1):
        n = inp.readline().strip()

        o = "Case #%d: %s"%(i, str(findnumber(n)))
        print o
        out.write('%s'%o)
        if i < cases:
            out.write('\n')
