#!/usr/bin/env python3
"""
Fashion Police
Code Jam 2016, Round 1C, Problem C

HOW TO USE:
#~: python c.py < input.in > output.out
"""


def fashion_large(jackets, pants, shirts, k):
    outfits = set()
    pairs_jp = dict()
    pairs_js = dict()
    pairs_ps = dict()
    for j in range(1, jackets + 1):
        for p in range(1, pants + 1):
            for s in range(1, shirts + 1):
                if (j, p, s) in outfits:
                    continue
                if pairs_jp.get((j, p), 0) >= k:
                    continue
                if pairs_js.get((j, s), 0) >= k:
                    continue
                if pairs_ps.get((p, s), 0) >= k:
                    continue

                outfits.add((j, p, s))
                pairs_jp[(j, p)] = pairs_jp.get((j, p), 0) + 1
                pairs_js[(j, p)] = pairs_js.get((j, s), 0) + 1
                pairs_ps[(j, p)] = pairs_ps.get((p, s), 0) + 1

    return outfits


def fashion_small(jackets, pants, shirts, k):
    outfits = set()
    if k >= shirts:
        for j in range(1, jackets + 1):
            for p in range(1, pants + 1):
                for s in range(1, shirts + 1):
                    outfits.add((j, p, s))
    elif k == 1:
        if jackets == 1:
            for p in range(1, pants + 1):
                outfits.add((1, p, p))
        elif jackets == 2:
            if pants == 2:
                for j in range(1, 3):
                    for p in range(1, 3):
                        outfits.add((j, p, j + p - 1))
                if shirts == 3:
                    outfits.add((1, 2, 3))
            elif pants == 3:
                for j in range(1, 3):
                    for p in range(1, 4):
                        s = (j + p - 2) % 3 + 1
                        outfits.add((j, p, s))
        elif jackets == 3:
            for j in range(1, 4):
                for p in range(1, 4):
                    s = (j + p - 2) % 3 + 1
                    outfits.add((j, p, s))
    elif k == 2:
        for j in range(1, max(jackets, 2) + 1):
            for p in range(1, pants + 1):
                for s in range(1, 3):
                    outfits.add((j, p, s))
        if jackets == 3:
            outfits.add((3, 1, 3))
            outfits.add((3, 2, 3))
            outfits.add((3, 3, 3))

    return outfits


def handle_case():
    """Handle the IO of the case, and return the answer"""
    jackets, pants, shirts, k = [int(x) for x in input().split(" ")]
    result = fashion_small(jackets, pants, shirts, k)

    return result


def handle_result(result):
    """Parse the result into the required format"""
    return str(len(result)) + "\n" + "\n".join(["{0} {1} {2}".format(*outfit) for outfit in result])


def main():
    """Get the number of cases, solve each case and print its result"""
    num_of_tests = int(input())

    # iterate over test cases
    for test_case in range(1, num_of_tests + 1):
        result = handle_case()
        printable_result = handle_result(result)
        print("Case #{}: {}".format(test_case, printable_result))


if __name__ == "__main__":
    main()
