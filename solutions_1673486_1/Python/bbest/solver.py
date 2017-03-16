import sys

def solver(a, b, ps):
    cases = []
    # case where we keep typing
    # prob that we got each key right
    prob_all_correct = reduce(lambda x, y:x*y, ps, 1)
    case1 = prob_all_correct*(b+1-a) + (1 - prob_all_correct)*(2*(b+1)-a)
    cases.append(case1)

    # case where we backspace between 1 and a-1 times
    # n = 1
    # while (2*n + b - a + 1) <= (b + 2):
    #     prob_all_correct = reduce(lambda x, y:x*y, ps[:a-n], 1)
    #     cases.append(prob_all_correct*(2*n + b - a + 1) + (1 - prob_all_correct)*(2*n + b - a + 1 + b + 1))
    #     n += 1

    # # (a+2)/2 to 0 backspaces
    n = (a + 2) / 2
    prob_all_correct = reduce(lambda x, y:x*y, ps[:a-n-1], 1)
    while n >= 1:
        prob_all_correct *= ps[a-n-1]
        cases.append(prob_all_correct*(2*n + b - a + 1) + (1 - prob_all_correct)*(2*n + b - a + 1 + b + 1))
        n -= 1

    # case where we return immediately
    # cases = []
    cases.append(b+2)


    return min(cases)

def ssi(s):
    """
    space separated integers
    """
    return map(int, s.strip('\n').split())

def ssr(s):
    """
    space separated reals
    """
    return map(float, s.strip('\n').split())

def rl():
    return sys.stdin.readline()

def debug(msg='', off=False):
    if not off:
        sys.stderr.write(str(msg) + '\n')

def main():
    # open input file
    # input_file = open('infile.txt')
    
    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        [a, b]  = ssi(rl())
        ps = ssr(rl())
        answer = solver(a, b, ps)
        output.append('Case #%d: %0.7f\n' % (c+1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()



if __name__=='__main__':
    main()
