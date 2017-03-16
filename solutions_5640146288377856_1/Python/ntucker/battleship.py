import sys
import math

output_line = "Case #{X:d}: {min:d}"


if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            R, C, W = map(int, inhandle.readline().split())


            # last row
            min = math.ceil(float(C) / W) + W - 1
            # other rows
            min += math.floor(float(C) / W) * (R - 1)

            outline = output_line.format(X=t + 1, min=min)
            print(outline, file=outhandle)
            print(outline)
            print()



