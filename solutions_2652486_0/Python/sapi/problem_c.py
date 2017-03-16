import random

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

    _,N,M,K = [int(x) for x in lines[0].strip().split(' ')]
    kss = [[int(x) for x in ln.strip().split(' ')] for ln in lines[1:]]
    return M,N,K,kss

def divisors(k, ns):
    if not k:
        return []

    res = []

    for i,n in enumerate(ns):
        if not k%n:
            rec = divisors(k/n, ns)
            if rec is None:
                continue
            else:
                if rec:
                    for r in rec:
                        res.append([n] + r)
                else:
                    res.append([n])
    return res

def sample_with_repeats(pop, n):
    res = []
    for _ in range(n):
        res.append(random.sample(pop,1)[0])
    return res

def process(data):
    """
    Return the str to write to file for this test case
    
    @param object $data
      the data structure for this problem

    @retval str
      the string to print for this test case (not including 'Case n: \n')

    """
    M,N,K,kss = data

    ns = range(2, M+1)
    lines = []

    for ks in kss:
        pns = []
        for k in ks:
            tpns = divisors(k, ns)
            if not tpns:
                continue

            f = False
            for poss in tpns:
                # if exactly this many were required
                #if len(poss) == N:
                #    print '*'.join(str(x) for x in poss) + '==' + str(k)
                #    pns = poss
                #    f = True
                #    break
                #else:
                    pns.extend(poss)

            if f:
                break

        lpns = len(pns)
        xs = []
        if lpns == N:
            xs = pns
        else:
            # Three conditions
            # (1) pns empty - have to guess from ns
            # (2) pns has too few numbers - use these, and guess the rest
            # (3) pns has too many numbers - guess from these
            # NB that all sampling must allow repeats
            if not pns:
                xs = sample_with_repeats(ns, N)
            elif lpns < N:
                xs = pns
                while len(xs) != N:
                    x = sample_with_repeats(ns,1)[0]
                    if x not in xs:
                        xs.append(x)
            else:
                xs = sample_with_repeats(pns, N)

        lines.append(''.join(str(x) for x in xs))
            
    return '\n'.join(lines)

def run(inpath, outpath):
    fin = open(inpath, 'rU')
    fout = open(outpath, 'w')

    s = ''
    case = 1
    r = None

    for i, line in enumerate(fin):
        if not i or not line.strip():
            continue
        
        if r is None:
            r = [int(x) for x in line.strip().split(' ')][0]
            s += line
            continue

        s += line
        r -= 1

        if r == 0:
            data = preprocess(s)
            res = process(data)
            cstr = 'Case #%d:\n%s\n'%(case, res)

            print cstr[:-1]
            fout.write(cstr)

            case += 1
            s = ''
            r = None

    fin.close()
    fout.close()
