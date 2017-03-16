# -*- coding: utf-8 -*-

import sys
from collections import defaultdict


def process(n, lines):
    counts = defaultdict(int)
    for line in lines:
        for height in line:
            counts[height] += 1
    res = []
    for height in counts:
        if counts[height] % 2 != 0:
            res.append(height)
    return sorted(res)






def main(path):

    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    count = 1
    i = 1
    while count <= t:
        n = int(content[i].replace("\n", ""))
        i += 1
        lines_to_read = 2 * n - 1
        lines = []
        for j in range(i, i + lines_to_read):
            line = [int(k) for k in content[j].replace("\n", "").split(" ")]
            lines.append(line)
        i = i + lines_to_read
        result = process(n, lines)
        print("Case #{}: {}".format(count, " ".join(map(str, result))))
        count += 1


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
