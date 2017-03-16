__author__ = 'gosu'

from math import log

def main():
    inp = open("rankandfile.in")
    out = open("rankandfile.txt", 'w')
    t = int(inp.readline())

    for casenum in range(t):
        n = int(inp.readline())
        numbers = {}
        for x in range(2*n-1):
            for soldier in [int(a) for a in inp.readline().split()]:
                numbers[soldier] = numbers.setdefault(soldier, 0) + 1
        rv = []
        for item in numbers.items():
            if item[1] % 2 == 1:
                rv.append(item[0])
        rv.sort()
        output = 'Case #{0}: {1}'.format(casenum+1, ' '.join([str(a) for a in rv]))
        print(output)
        out.write(output)
        out.write('\n')
    out.close()



if __name__ == '__main__':
    main()