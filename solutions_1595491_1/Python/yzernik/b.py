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
    result = 0
    s_remaining = s
    i = 0
    for t_j in t:
        i += 1
        if t_j >= p*3:
            result += 1
        elif t_j >= p*3 - 2 and (p-1) >= 0: 
            result += 1
        elif s_remaining > 0:
            if t_j >= p*3 - 4 and (p-2) >= 0:
                result += 1
                s_remaining -= 1
    return result

if __name__ == '__main__':
    infile = str(sys.argv[1])
    outfile = str(sys.argv[2])
    solve_b(infile, outfile)
