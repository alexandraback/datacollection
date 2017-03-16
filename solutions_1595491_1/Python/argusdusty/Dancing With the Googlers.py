import sys

def dancing_with_the_googlers(args):
    a = args.split(' ')
    N = int(a[0])
    S = int(a[1])
    p = int(a[2])
    t = [int(i) for i in a[3:]]
    r = []
    r = [[((i + 2) // 3) >= p, i > 1 and i < 29 and ((i + 4) // 3) >= p] for i in t]
    a = sum([1 for i in r if i[0]])
    b = sum([1 for i in r if i[1] and not i[0]])
    if b > S:
        return str(a + S)
    return str(a + b)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    for i in range(1, int(Input[0]) + 1):
        args = Input[i]
        result = dancing_with_the_googlers(args)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
