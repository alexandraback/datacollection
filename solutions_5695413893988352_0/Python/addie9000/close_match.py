import sys


def solve_case(c, j, case_number):
    cl = list(c)
    jl = list(j)

    csl = []
    jsl = []
    balance = None
    for cj in zip(cl, jl):
        if cj[0] == '?':
            if cj[1] == '?':
                if balance is None:
                    csl.append('0')
                    jsl.append('0')
                elif balance == 'c':
                    csl.append('0')
                    jsl.append('9')
                else:
                    csl.append('9')
                    jsl.append('0')
            else:
                if balance is None:
                    csl.append(cj[1])
                    jsl.append(cj[1])
                elif balance == 'c':
                    csl.append('0')
                    jsl.append(cj[1])
                else:
                    csl.append('9')
                    jsl.append(cj[1])
        else:
            if cj[1] == '?':
                if balance is None:
                    csl.append(cj[0])
                    jsl.append(cj[0])
                elif balance == 'c':
                    csl.append(cj[0])
                    jsl.append('9')
                else:
                    csl.append(cj[0])
                    jsl.append('0')
            else:
                csl.append(cj[0])
                jsl.append(cj[1])
                if balance is None:
                    if int(cj[0]) > int(cj[1]):
                        balance = 'c'
                    elif int(cj[0]) < int(cj[1]):
                        balance = 'j'
    print("Case #%d: %s %s" % (case_number, "".join(csl), "".join(jsl)))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        cj = r.readline().strip().split(' ')

        solve_case(cj[0], cj[1], case_number)


if __name__ == '__main__':
    main()
