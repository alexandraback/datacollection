
def preprocess(s):
    """
    Return the data structure built from the raw string (for one test case)
    read from the file

    @param str $s
      the full string (including newlines) read from the file, for a single
      test case

    @retval object
      the data structure for this problem

    """
    lines = s.splitlines()
    E,R,_ = [int(x) for x in lines[0].strip().split(' ')]
    vi = [int(x) for x in lines[1].strip().split(' ')]

    return (E, R, vi)

def process(data):
    """
    Return the str to write to file for this test case
    
    @param object $data
      the data structure for this problem

    @retval str
      the string to print for this test case (not including 'Case n: \n')

    """
    E, R, vi = data # max energy, energy regained, values
    
    #gain = lambda e, v: e*v # amount of energy spent * value

    return str(stuff(E, E, R, vi[:]))

def stuff(Emax, E, R, vs):
    if not vs or E < 0:
        return 0
    
    if E > Emax:
        E = Emax

    y = 0

    if E == Emax:
        es = range(min(R,E), E+1)
    else:
        es = range(0, E+1)

    for i,v in enumerate(vs):
        ys = [e*v + stuff(Emax, E + R - e, R, vs[i+1:]) for e in es]

        yi = max(ys)
        
        for j,x in enumerate(ys):
            if x == yi:
                ind = j

        e = es[ind]
        E += R - e

        if yi > y:
            y = yi
    
    return y


def run(inpath, outpath):
    fin = open(inpath, 'rU')
    fout = open(outpath, 'w')

    s = ''
    case = 1
    pos = 0

    for i, line in enumerate(fin):
        if not i:
            continue
        
        s += line
        pos += 1
        if pos == 2:
            data = preprocess(s)
            res = process(data)
            cstr = 'Case #%d: %s\n'%(case, res)

            print cstr[:-1]
            fout.write(cstr)

            case += 1
            s = ''
            pos = 0

    fin.close()
    fout.close()
