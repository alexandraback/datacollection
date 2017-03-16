import sys
import string

def solve_b(infile, outfile):
    f = open(infile, 'r')
    r = open(outfile, 'w')
    num_cases = int(f.readline())
    for case_index in range(num_cases):
        line = str(f.readline().rstrip('\n'))
        n, s, p, t = get_inputs(line)
        case_answer = max_googlers(n, s, p, t)
        r.write("Case #" + str(case_index+1) + ": " + str(case_answer) + "\n")

def get_inputs(text):
    e = text.split(' ')
    return int(e[0]), int(e[1]), int(e[2]), [int(n) for n in e[3:]]

def max_googlers(n, s, p, t):
    if n == 0:
        return 0
    elif n == 1:
        if t[0] >= p*3:
            return 1
        elif t[0] >= p*3 - 2 and (p-1) >= 0: 
            return 1
        elif s > 0:
            if t[0] >= p*3 - 4 and (p-2) >= 0:
                return 1
            else:
                return 0
        else:
            return 0
    else:
        returnval =  max(max_googlers(n-1, s, p, t[:-1]) + max_googlers(1, 0, p, [t[-1]]),
                         max_googlers(n-1, max(s-1, 0), p, t[:-1]) + max_googlers(1, min(1, s), p, [t[-1]]))
        return returnval

if __name__ == '__main__':
    infile = str(sys.argv[1])
    outfile = str(sys.argv[2])
    solve_b(infile, outfile)
