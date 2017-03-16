import sys
import os, os.path
import functools

def solve(a, motes):
    if a == 1:
        #Special case, we can't eat anything
        #need to remove all the motes
        return len(motes)

    while motes and a > motes[0]:
        a += motes.pop(0)

    if len(motes) == 0:
        return 0

    num_moves = 0
    remaining_motes = len(motes)

    while a <= motes[0]:
        a += a - 1
        num_moves += 1

    num_moves += solve(a, motes)

    return min(num_moves, remaining_motes)

if __name__ == "__main__":
    input_path = sys.argv[1]
    output_path = os.path.splitext(input_path)[0] + ".out"
    output = []
    with open(input_path) as input_file:
        num_cases = int(input_file.readline().strip())

        for i in range(num_cases):
            a, numo = [int(x) for x in input_file.readline().strip().split(" ")]
            motes = [int(x) for x in input_file.readline().strip().split(" ")]
            motes.sort()
            num_moves = solve(a, motes)
            output.append("Case #{}: {}".format(i+1, num_moves))
            print(i, num_cases)
    with open(output_path, "w") as output_file:
        for o in output:
            output_file.write(o + "\n")
