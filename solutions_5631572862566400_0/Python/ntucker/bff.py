import sys
import itertools
from collections import defaultdict

output_line = "Case #{X:d}: {answer:d}"


# TODO: what about totally alone child ccycles
def longest_path(end, mapping):
    largest = 0 if end is None else 0
    best_seen = set()
    print('longest', end, mapping)
    for start in mapping.keys():
        if end is None:
            realend = start
            print()
        else:
            realend = end

        seen = set([start])
        cur_child = start
        while True:
            next_child = mapping[cur_child]

            if next_child not in mapping.keys():
                break

            if next_child == realend:
                # largest = max(largest, len(seen))
                num = len(seen)

                extra_seen = []
                # end depth of search should add the additional pairings
                if end is not None:
                    # print('checking')
                    for child, bff in ((k, v) for k, v in mapping.items() if k not in seen):
                        if child == mapping.get(bff, None):
                            print('extra', child, bff)
                            num += 1
                            extra_seen.append(child)
                if num > largest:
                    largest = num
                    best_seen = seen.union(extra_seen)
                break
            if next_child in seen:  # we can't reach out destination
                break
            if mapping[next_child] == cur_child and next_child != end and cur_child != end:  # they like each other!
                # seen.add(next_child)
                newmap = {k:v for k, v in mapping.items() if k not in seen}
                big, otherseen = longest_path(next_child, newmap)
                newval = len(seen) + 1 + big
                if newval > largest:
                    print('from', start, 'used', seen, 'size', newval)
                    print({k:v for k, v in mapping.items() if k not in seen})
                    best_seen = otherseen | seen
                largest = max(largest, newval)
                break

            seen.add(next_child)
            cur_child = next_child


    return largest, best_seen


if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            size = int(inhandle.readline().strip())
            bffs = list(map(lambda n: int(n) - 1, inhandle.readline().strip().split()))

            print()
            print()
            print('starting', {i:v for i, v in enumerate(bffs)})
            largest, chain = longest_path(None, {i:v for i, v in enumerate(bffs)})

            outline = output_line.format(X=t + 1, answer=largest)
            print(outline, file=outhandle)
            print(outline)
