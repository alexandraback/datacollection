#!/usr/bin/python3
import sys

def main():
    infile = open(sys.argv[1], "r")
    outfile = open(sys.argv[1][:-2] + "out", "w")

    for case in range(1, int(infile.readline())+1):
        a, b, k =  (list(range(int(i))) for i in infile.readline().split())

        output = 0

        for i in a:
            for j in b:
                if i&j in k:
                    output += 1

        print("Case #{0}: {1}".format(case, output), file=outfile)

if __name__ == "__main__":
        main()
