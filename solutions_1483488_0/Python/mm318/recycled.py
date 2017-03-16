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

        A = int(in_strs[0])
        B = int(in_strs[1])
        digits = len(in_strs[0])

        num_pairs = 0
        for n in range(A,B,1):
            n_str = str(n)
            found_m = {}
            for i in range(1, digits):
                m_str = n_str[-i:digits] + n_str[0:-i]
                m = int(m_str)
                if(m in found_m):
                    print("duplicate found (%d, %d)" % (n,m))
                    continue
                if(m <= B and m > n):
                    num_pairs+=1
                    found_m[m] = True
                    # print("(%d, %d)" % (n, m), file=output_file)
        print("Case #%d: %d" % (k+1, num_pairs), file=output_file)

    # n_str = "abcdef"
    # digits = len(n_str)
    # for i in range(1,digits):
    #     new_str = n_str[-i:digits] + n_str[0:-i]
    #     print(new_str)

    input_file.close()
    output_file.close()


if(__name__ == "__main__"):
    sys.exit(main(*sys.argv))

