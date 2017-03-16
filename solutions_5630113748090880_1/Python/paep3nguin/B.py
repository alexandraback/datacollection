#! python3

from collections import Counter

def main():
    with open("B-large.in") as in_file:
        with open("B-large.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                N = int(in_file.readline().replace('\n', ''))
                nums = []

                for i in range(2*N-1):
                    nums.extend([int(n) for n in in_file.readline().replace('\n', '').split()])

                counts = Counter(nums)

                missing = []

                for k, v in counts.items():
                    if v % 2 != 0:
                        missing.append(k)

                fout.write("Case #{0}: {1}\n".format(x + 1, " ".join([str(x) for x in sorted(missing)])))

if __name__ == "__main__":
    main()
