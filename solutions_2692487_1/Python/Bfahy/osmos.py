#!/usr/bin/env python3
import argparse

parser = argparse.ArgumentParser(description="google code jam 1b osmos")
parser.add_argument("inputfile", type=str, help="input file")
args = parser.parse_args()
outfile = open(args.inputfile + ".out", "w")


def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        A, N = (int(i) for i in f.readline().split())
        sizes = [int(i) for i in f.readline().split()]
        yield A, sizes


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)


def solveable(mysize, sizes):
    for s in sorted(sizes):
        if mysize > s:
            mysize+=s
        else:
            return False
    return True

def solve(mysize, sizes):
    changes = 0
    for index,s in enumerate(sorted(sizes),start=0):
        if mysize > s:
            print("absorbing {}, mysize {}, mynewsize {}".format(s, mysize, mysize+s))
            mysize+=s
        else:
            diff = s-mysize

            # if(mysize < 2):
            #     ss = sorted(sizes)
            #     print(ss)
            #     i = ss.index(s)
            #     print(i)
            #     len(ss[i:])
            #     print(ss[i:])
            #     changes+= len(ss[i:])
            #     return changes
            count = 0
            remaining = len(sizes) - index
            while(mysize <= s):
                count += 1
                print(count, remaining)
                if(count >= remaining):
                    print("removing rather than adding")
                    print(remaining)
                    return changes+remaining
                print("adding {} and absorving, mysize {}, mynewsize {}".format(mysize-1, mysize, mysize+(mysize-1)))
                mysize+=(mysize-1)
                # changes+=1
            print("absorbing {}, mysize {}, mynewsize {}".format(s, mysize, mysize+s))
            mysize+=s
            changes+=count

    return changes


def main():
    for n, case in enumerate(read_input(), start=1):
        print("case {} is {}".format(n, repr(case)))
        mysize, sizes = case
        outstring = ""
        if(solveable(mysize, sizes)):
            outstring=0

        if(mysize < 2):
            outstring = len(sizes)
        else:
            outstring = solve(mysize, sizes)

        # if outstring > len(sizes):
        #     print("outstring {} bigger than {}".format(outstring,len(sizes)))
        #     raise ValueError
        outstring = min(len(sizes), outstring)
        output(n, outstring)


if __name__ == "__main__":
    main()
