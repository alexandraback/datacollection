from sets import Set;

def abc(x):
    if (x == 0):
        return 'INSOMNIA'
    y = x;
    quit = False;
    digits = Set([]);
    for c in str(y):
        digits.add(c);
    if len(digits) == 10:
        quit = True;
    while (not quit):
        y += x;
        for c in str(y):
            digits.add(c);

        if len(digits) == 10:
            quit = True;

    return str(y)

if __name__ == "__main__":
    import sys;
    with open(sys.argv[1]) as f:
        s = f.readline();
        T = int(s);
        for t in range(T):
            s = f.readline();
            print "Case #{}: {}".format(t+1, abc(int(s)))

