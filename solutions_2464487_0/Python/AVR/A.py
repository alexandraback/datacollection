import sys
import math

def main():
    infile = open(sys.argv[1])
    outfile = open(sys.argv[1][:-2] + 'out', 'w')
    numcases = int(infile.readline())

    for case in range(numcases):
        r,t = (int(k) for k in infile.readline().split())


        out = int(math.floor(((0.25 * (1-2*r + math.sqrt((2*r - 1)**2 + 8*t))))))

        while 2*(out**2)+(2*r-1)*out - t>0:
            out -= 1

        print('Case #%d:' % (case + 1), int(out), file=outfile)





if __name__ == '__main__':
    main()
