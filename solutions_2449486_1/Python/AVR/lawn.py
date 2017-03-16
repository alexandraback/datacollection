import sys


def main():
    infile = open(sys.argv[1])
    outfile = open(sys.argv[1][:-2] + 'out', 'w')
    numcases = int(infile.readline())

    for case in range(numcases):
        N,M = (int(n) for n in infile.readline().split())
        lawn = []
        for i in range(N):
            row = infile.readline().split()
            lawn += [[int(n) for n in row]]
        rotlawn = list(zip(*lawn))
        isgood = True
        for row in range(N):
            for col in range(M):
                maybegood = False
                h = lawn[row][col]
                if all(h>=k for k in lawn[row]) or all(h >= k for k in rotlawn[col]):
                    maybegood = True
                if not maybegood:
                    isgood = False

        if isgood:
            out = 'YES'
        else:
            out = 'NO'

        print('Case #%d:' % (case + 1), out, file=outfile)





if __name__ == '__main__':
    main()
