import sys

i_name = sys.argv[1]
o_name = sys.argv[2]


def rec(e, r, v, first = None, best_e = None, end = None):
    if not best_e:
        best_e = e
    if not first:
        first = 0
    print "recu", v
    s = 0
    if not v:
        return 0
    if len(v) == 1:
        if not first:
            s = r * v[0]
        else:
            s = first * v[0]
    else:
        end_e = first + r * (len(v) - 1)
        print "end_e", end_e
        if end_e <= best_e:
            s += v[-1] * end_e
        else:
            s += best_e * v[-1]
        v = v[:-1]
        m = max(v)
        tmp = list()
        for element in v:
            tmp.append(element)
            if element == m:
                s += rec(e, r, tmp)
                tmp = list()
        s += rec(e, r, tmp)
    print "ret", s
    return s

with open(i_name) as f:
    with open(o_name, 'w') as g:
        l = list()
        d = dict()
        for index, line in enumerate(f.readlines()[1:]):
            line = line[:-1] if line[-1] == '\n' else line
            if not d:
                d['E'], d['R'], d['N'] = [int(a) for a in line.split()]
            else:
                d['V'] = [int(a) for a in line.split()]
                l.append(d)
                d = dict()
                
        for index, d in enumerate(l):
            E, R, N, V = d['E'], d['R'], d['N'], d['V']
            ##############################################
            out = 0
            m = max(V)
            tmp = list()
            f = False
            for element in V:
                tmp.append(element)
                if element == m:
                    first = 0
                    if not f:
                        first = E
                    out += rec(E, R, tmp, first = first)
                    tmp = list()
            out += rec(E, R, tmp)
            
            ##############################################
            g.write("Case #%d: %d\n" % (index + 1, out))
