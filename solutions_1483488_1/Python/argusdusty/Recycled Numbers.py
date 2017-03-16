import sys

def recycled_numbers(args):
    args = args.split(' ')
    mn = int(args[0])
    mx = int(args[1])
    c = 0
    d = len(str(mn)) - 1
    e = 10 ** d
    for i in range(mn, mx - 1):
        x = i
        r = set()
        for j in range(d):
            x = 10*(x % e) + (x // e)
            if x > i and x <= mx:
                r.add((i, x))
        c += len(r)
    return str(c)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    for i in range(1, int(Input[0]) + 1):
        args = Input[i]
        result = recycled_numbers(args)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
