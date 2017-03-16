import sys
import math

def solve(instream):
    x, y = [int(x) for x in instream.readline().strip().split(" ")]

    min_steps = int(math.ceil((math.sqrt(8 * (abs(x) + abs(y)) + 1) + 1) / 2.0))

    while True:
        cur_x, cur_y = x, y
        steps_rev = []

        for i in range(min_steps, 0, -1):
            if abs(cur_x) > abs(cur_y):
                if cur_x > 0:
                    steps_rev.append("W")
                    cur_x -= i
                else:
                    steps_rev.append("E")
                    cur_x += i
            else:
                if cur_y > 0:
                    steps_rev.append("S")
                    cur_y -= i
                else:
                    steps_rev.append("N")
                    cur_y += i

        if (cur_x, cur_y) == (0, 0):
            break

        min_steps += 1

    result_map = {
        "N": "S",
        "S": "N",
        "E": "W",
        "W": "E",
    }

    result = "".join(result_map[x] for x in reversed(steps_rev))

    return result


def run(input=sys.stdin):
    cases = int(input.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve(input)))

if __name__ == "__main__":
    run()
