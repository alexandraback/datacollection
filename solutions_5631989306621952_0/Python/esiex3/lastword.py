__author__ = 'gosu'

from math import log

def main():
    inp = open("lastword.in")
    out = open("lastword.txt", 'w')
    t = int(inp.readline())

    for casenum in range(t):
        line = inp.readline()
        rv = []
        for letter in line:
            if not rv:
                rv.append(letter)
            else:
                if rv[0] <= letter:
                    rv.insert(0, letter)
                else:
                    rv.append(letter)
        output = 'Case #{0}: {1}'.format(casenum+1, ''.join(rv))
        print(output)
        out.write(output)
    out.close()



if __name__ == '__main__':
    main()