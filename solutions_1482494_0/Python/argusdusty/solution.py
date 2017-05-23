import sys

def setup(args, i, s):
    t = [i*1 for i in args]
    if args[i][1] <= s:
        t[i][2] = 2
        return t
    t[i][2] += 1
    return t

def brute(args):
    s = sum(i[2] for i in args)
    if s == 2*len(args): return 0
    choices = [i for i in range(len(args)) if args[i][2] != 2 and (args[i][0] <= s or args[i][1] <= s)]
    for i in choices:
        if args[i][1] <= s:
            b = brute(setup(args, i, s))
            if b == -1: return b
            return b+1
        elif args[i][2] == 1 and args[i][0] <= s:
            b = brute(setup(args, i, s))
            if b == -1: return b
            return b+1
        
    if len(choices) == 0: return -1
    b = min(brute(setup(args, i, s)) for i in choices)
    if b == -1: return b
    return b+1

def best_two(args, s):
    for i in range(len(args)):
        if args[i][1] <= s and args[i][2] == 0: return i
    return -1

def best_one(args, s):
    mn, mx, pos = 2001, 0, -1
    for i in range(len(args)):
        if args[i][2] == 1 and args[i][1] <= s: return i
        if args[i][0] > s or args[i][0] != 0: continue
        if args[i][1] > mx:
            mn = args[i][0]
            mx = args[i][1]
            pos = i
        if args[i][0] == mx and args[i][1] < mn:
            mn = args[i][0]
            mx = args[i][1]
            pos = i
    return pos

def kingdom_rush(args):
    args = [[int(i.split(' ')[0]), int(i.split(' ')[1]), 0] for i in args]
    b = brute(args)
    if b == -1: return "Too Bad"
    return str(b)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    x = 0
    for i in range(1, int(Input[0]) + 1):
        n = int(Input[i+x])
        args = [Input[i+x+j] for j in range(1, n + 1)]
        x += n
        result = kingdom_rush(args)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
