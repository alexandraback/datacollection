
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
    return [int(x) for x in s.strip().split(' ')]

def process(data):
    """
    Return the str to write to file for this test case
    
    @param object $data
      the data structure for this problem

    @retval str
      the string to print for this test case (not including 'Case n: \n')

    """
    r, t = data

    y = 0
    while 1:
        # white circle
        r_white = r
        r_black = r + 1
        
        t_this = r_black**2 - r_white**2
        
        if (t - t_this) < 0:
            break
        t -= t_this

        r = r_black + 1
        y += 1

    return str(y)


def run(inpath, outpath):
    fin = open(inpath, 'rU')
    fout = open(outpath, 'w')

    case = 1

    for i, line in enumerate(fin):
        if not i:
            continue
    
        data = preprocess(line)
        res = process(data)
        cstr = 'Case #%d: %s\n'%(case, res)

        print cstr[:-1]
        fout.write(cstr)

        case += 1

    fin.close()
    fout.close()
