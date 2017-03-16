#!/usr/bin/env python3
"""
Slides!
Code Jam 2016, Round 1C, Problem B

HOW TO USE:
#~: python b.py < input.in > output.out
"""


def slides(buildings, ways):
    if ways > 2 ** (buildings - 2):
        return None

    middle_slides = ["".join(["0"] * (s + 1) + ["1"] * (buildings - s - 1))
                     for s in range(1, buildings - 1)]
    last_slides = "".join(["0"] * buildings)

    if ways == 2 ** (buildings - 2):
        first_slides = "".join(["0"] + ["1"] * (buildings - 1))
    else:
        bin_ways = ("{0:0%db}" % (buildings - 2)).format(ways)
        first_slides = "".join(["0"] + [x for x in bin_ways] + ["0"])

    return [first_slides] + middle_slides + [last_slides]


def handle_case():
    """Handle the IO of the case, and return the answer"""
    buldings, ways = [int(x) for x in input().split(" ")]
    result = slides(buldings, ways)

    return result


def handle_result(result):
    """Parse the result into the required format"""
    if not result:
        return "IMPOSSIBLE"

    return "\n".join(["POSSIBLE"] + result)


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
