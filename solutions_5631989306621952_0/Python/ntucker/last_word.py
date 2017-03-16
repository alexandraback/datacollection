import sys
import itertools

output_line = "Case #{X:d}: {answer}"


if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            word = inhandle.readline().strip()
            last = [word[0]]

            for c in word[1:]:
                if c >= last[0]:
                    last[0:0] = [c]
                else:
                    last.append(c)


            outline = output_line.format(X=t + 1, answer=''.join(last))
            print(outline, file=outhandle)
            print(outline)
