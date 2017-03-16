filename = "a.in"
outfilename = "output.txt"

def solve(f):
    n = int(f.readline())
    count = 0

    while n >= 1:
        print n
        s = str(n)
        l = len(s)
        if l == 1:
            count += n
            n = 0
            continue

        msd = int(s[:l/2])
        lsd = int(s[(l+1)/2:])
        if lsd > 1:
            count = count + lsd - 1
            n = n - lsd + 1
        elif int(str(msd)[::-1]) == lsd or lsd == 0:
            count = count + 1
            n = n - 1
        else:
            count += 1
            n = int(s[::-1])


    output = count
    return output

def out(s, o):
    print s
    o.write("{}\n".format(s))

def main():
    f = open(filename)
    o = open(outfilename, 'w+')
    T = int(f.readline())
    t = 1
    while t <= T:
        output = solve(f)
        out("Case #{}: {}".format(t, output), o)
        t+=1

if __name__ == "__main__":
    main()
