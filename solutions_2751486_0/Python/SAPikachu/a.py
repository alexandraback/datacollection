import sys
import re

vowels = ("a", "e", "i", "o", "u")

def solve(instream):
    name, n = instream.readline().strip().split(" ")
    n = int(n)

    result = 0
    c_count = 0

    last_start = 0

    for i in range(len(name) + 1):
        if i < len(name) and name[i] not in vowels:
            c_count += 1
            continue

        if c_count >= n:
            ch_after = len(name) - i

            subs_before = name[:i - c_count]
            if last_start > 0:
                ch_before = i - c_count - last_start + n - 1
            else:
                ch_before = i - c_count

            # Full substring
            result += (ch_before + 1) * (ch_after + 1)

            # + Before
            result += (ch_before + 1) * (c_count - n)

            # + After
            result += (ch_after + 1) * (c_count - n)

            # + Inner
            inner = c_count - n - 1
            if inner > 0:
                result += int(inner * (inner + 1) / 2) 

            last_start = i

        c_count = 0

    return result


def run(input=sys.stdin):
    cases = int(input.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve(input)))

if __name__ == "__main__":
    run()
