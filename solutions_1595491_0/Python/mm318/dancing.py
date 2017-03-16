#!/usr/bin/env python

from __future__ import print_function
import sys

def main(*args):
    global translation

    if(len(args) < 2):
        print("Usage: %s <input file>" % args[0])

    filename = args[1]
    input_file = open(filename, "rb")
    output_file = open(filename+".out", "wb")

    try:
        in_str = input_file.readline().strip()
    except:
        print("Premature end of input")

    T = int(in_str)
    for k in range(T):
        in_strs = input_file.readline().split()

        N = int(in_strs[0])
        S = int(in_strs[1])
        p = int(in_strs[2])
        ti = []
        for i in range(N):
            ti.append(int(in_strs[3+i]))

        max_num = 0;
        for t in ti:
            if(t < p):
                continue
            elif(float(t)/3.0 >= p):
                max_num += 1
            elif(t%3 == 2 and t/3+1 >= p):
                max_num +=1
            elif(t%3 == 1 and t/3+1 >= p):
                max_num +=1
            elif(S > 0):
                if(t%3 == 2 and t/3+2 >= p):
                    max_num +=1
                    S -= 1
                elif(t%3 == 0 and t/3+1 >=p):
                    max_num +=1
                    S -= 1
        print("Case #%d: %d" % (k+1, max_num), file=output_file)

    input_file.close()
    output_file.close()


if(__name__ == "__main__"):
    sys.exit(main(*sys.argv))

