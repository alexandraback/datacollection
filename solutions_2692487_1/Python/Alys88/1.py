"""
GCJ 2013
url http://code.google.com/codejam/contest/2434486/dashboard
"""
import sys

def bestMove(size, motes):
    if len(motes) == 0:
        return 0
    m = motes.pop(0)
    while size > m:
        size+=m
        try:
            m = motes.pop(0)
        except IndexError:
            #couldn't pop, everything has been eaten
            return 0

    #moves to grow
    g = 0
    gsize = size
    while gsize <= m:
        gsize += gsize-1
        g += 1
    #moves to delete
    # d = len(motes) + 1
    return min(g + bestMove(gsize, [m]+motes[:]), len(motes) + 1)

def process(f, output):
    nb_of_cases = int(f.readline().rstrip())
    for n in range(1, nb_of_cases + 1):
        print('Case', n)

        A,N = (int(x) for x in f.readline().rstrip().split())
        motes = [int(x) for x in f.readline().rstrip().split()]
        motes.sort()
        if A == 1:
            answer = N
        else:
            answer = bestMove(A, motes)

        print('Answer:', answer)
        output.write('Case #{0}: {1}\n'.format(n, answer))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)
