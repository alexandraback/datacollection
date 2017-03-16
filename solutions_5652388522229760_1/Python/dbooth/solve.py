#python 2.7

import sys
import math

def solve(N):
    if N == 0:
        return "INSOMNIA"
    digits_found = set()
    i = 1
    while True:
        Sn = str(N*i)
        for c in Sn:
            digits_found.add(c)
        if len(digits_found) == 10:
            return Sn
        i += 1

def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        res = solve(int(split_input[i+1]))
        output_file.write("Case #" + str(i + 1) + ": " + res + "\n")
    
if __name__ == "__main__":
    main()
