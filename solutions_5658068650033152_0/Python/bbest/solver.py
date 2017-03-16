import sys

DEBUG = True


def solver(n, m, k):
    if n > m:
        n, m = m, n
    if n <=2 or m <= 2:
        return k
    if n == 3 and m == 3:
        if k > 4:
            return k - 1
        return k
    if n == 3 and m == 4:
        if k < 5:
            return k
        elif k < 8:
            return k -1
        else:
            return k - 2
    if n == 3 and m == 5:
        if k < 5:
            return k
        elif k < 8:
            return k -1
        elif k < 11:
            return k - 2
        else:
            return k - 3
    if n == 4 and m == 4:
        if k < 5:
            return k
        elif k < 8: # capture 1
            return k -1
        elif k < 11: # capture 2
            return k - 2
        elif k < 13:
            return 8
        elif k == 13:
            return 9
        elif k == 14:
            return 10
        elif k == 15:
            return 11
        elif k == 16:
            return 12

    if n == 4 and m == 5:
        if k < 5:
            return k
        elif k < 8: # capture 1
            return k -1
        elif k < 11: # capture 2
            return k - 2
        elif k < 13:
            return 8
        elif k == 13:
            return 9
        elif k < 17:
            return 10
        else:
            return k - 6
    return 0


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
        debug('Case #%d' % (c + 1))
        n, m, k = ssi(rl())
        answer = solver(n, m, k)
        output.append('Case #%d: %s\n' % (c + 1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()


if __name__ == '__main__':
    main()
