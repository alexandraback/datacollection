import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in range(c):
            strs = f.readline().strip().split()
            yield case, (strs)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print(s)
    f.write(s + "\n")

def problem(scores):
    code = scores[0]
    jam = scores[1]
    c_current = 0
    j_current = 0
    letters = len(code)
    for c,j in zip(code, jam):
        if c != '?' and j != '?':
            c_current = c_current*10 + int(c)
            j_current = j_current*10 + int(j)
        elif c == '?' and j!='?':
            if c_current < j_current:
                c_current = c_current*10 + 9
            elif c_current == j_current:
                c_current = c_current*10 + int(j)
            elif c_current > j_current:
                c_current = c_current*10 + 0
            j_current = j_current*10 + int(j)
        elif c != '?' and j=='?':
            if j_current < c_current:
                j_current = j_current*10 + 9
            elif c_current == j_current:
                j_current = j_current*10 + int(c)
            elif j_current > c_current:
                j_current = j_current*10 + 0
            c_current = c_current*10 + int(c)
        else:
            if j_current < c_current:
                j_current = j_current*10 + 9
                c_current = c_current*10 + 0
            elif c_current == j_current:
                j_current = j_current*10 + 0
                c_current = c_current*10 + 0
            elif j_current > c_current:
                j_current = j_current*10 + 0
                c_current = c_current*10 + 9
    return str(c_current).zfill(letters) + ' ' + str(j_current).zfill(letters)

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

