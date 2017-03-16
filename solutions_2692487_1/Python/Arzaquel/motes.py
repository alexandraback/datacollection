import sys, math

infile = open("input.in")
outfiles = (sys.stdout, open("output.out", 'w'))

def do_output(number, output, outfiles):
    for f in outfiles:
        print('Case #%d:' % number, output, file=f)

def main():
    n = int(infile.readline())
    for i in range(n):
        s, m = [int(x) for x in infile.readline().split()]
        motes = [int(x) for x in infile.readline().split()]
        assert m == len(motes)
        do_output(i+1, do_task(s,motes), outfiles)

def do_task(s, motes):
    motes.sort()
    if s == 1:
        return len(motes)

    c = s
    o = 0
    opts = [0 for x in motes]
    for i in range(len(motes)):
        while(c <= motes[i]):
            c = c*2 - 1
            o = o + 1
        c = c + motes[i]
        opts[i] = o
    r = min(opts[-1], len(motes))
    for i in range(len(motes)):
        r = min(r,opts[i] + len(motes) - (i + 1))

    return r

if __name__=='__main__':
    main()
