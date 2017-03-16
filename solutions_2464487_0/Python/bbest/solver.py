import sys
from math import ceil

DEBUG = True

def solver(r, t):
    max_n = int(ceil((t + 1) / 2))
    return bin_search(max_n, 1, r, t)

def thickness(n, r):
    max_radius = r + (n - 1) * 2 + 1
    return n * (2 * max_radius) - 2*(n - 1)*n - n

def bin_search(upper, lower, r, t):
    debug(upper, lower)
    # lower always possible
    if upper - lower <= 1:
        return lower
    # will round down
    mid = int((upper + lower) / 2)
    if thickness(mid, r) <= t:
        return bin_search(upper, mid, r, t)
    else:
        return bin_search(mid, lower, r, t)


def ssi(s, func=int):
    """
    space separated integers
    """
    return map(func, s.strip('\n').split())

def rl():
    return sys.stdin.readline()

def debug(*args):
    if args[-1] is not False and DEBUG:
        msg = " ".join([str(m) for m in args])
        sys.stderr.write(msg + '\n')

def main():
    # open input file
    # input_file = open('infile.txt')
    
    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        debug('Case #%d' % (c+1))
        r, t = ssi(rl())
        answer = solver(r, t)
        debug(answer)
        output.append('Case #%d: %s\n' % (c+1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()



if __name__=='__main__':
    main()
