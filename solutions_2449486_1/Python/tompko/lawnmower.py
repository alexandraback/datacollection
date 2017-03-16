import sys
import os, os.path

def possible(w, h, lawn):
    valid = [[False for i in range(w)] for j in range(h)]

    for i in range(h):
        maxr = 0
        for j in range(w):
            maxr = max(maxr, lawn[i][j])
        for j in range(w):
            if lawn[i][j] == maxr:
                valid[i][j] = True

    for j in range(w):
        maxr = 0
        for i in range(h):
            maxr = max(maxr, lawn[i][j])
        for i in range(h):
            if lawn[i][j] == maxr:
                valid[i][j] = True

    for i in range(h):
        for j in range(w):
            if not valid[i][j]:
                return False

    return True

if __name__ == "__main__":
    input_path = sys.argv[1]
    output_path = os.path.splitext(input_path)[0] + ".out"
    output = []
    with open(input_path) as input_file:
        num_cases = int(input_file.readline().strip())

        for i in range(num_cases):
            h, w = map(int, input_file.readline().strip().split(" "))
            lawn = []
            for j in range(h):
                lawn.append([x for x in map(int, input_file.readline().strip().split(" "))])
            if possible(w, h, lawn):
                output.append("Case #{0}: YES".format(i+1))
            else:
                output.append("Case #{0}: NO".format(i+1))
            print(i, num_cases)

    with open(output_path, "w") as output_file:
        for o in output:
            output_file.write(o + "\n")
