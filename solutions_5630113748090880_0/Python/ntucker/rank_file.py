import sys
import itertools
from collections import defaultdict

output_line = "Case #{X:d}: {answer}"


if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            size = int(inhandle.readline().strip())
            heights = defaultdict(int)
            for n in range(2 * size - 1):
                line = map(int, inhandle.readline().strip().split())
                for height in line:
                    heights[height] += 1
            print(heights)

            missing = []
            for height, count in heights.items():
                if count % 2 == 1:
                    missing.append(height)
            missing.sort()

            assert(len(missing) == size)
            outline = output_line.format(X=t + 1, answer=' '.join(map(str, missing)))
            print(outline, file=outhandle)
            print(outline)
