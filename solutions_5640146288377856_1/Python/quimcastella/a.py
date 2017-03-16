import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            r, c, w = map(int, f.readline().split())
            yield case, (r,c,w)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def problem(r,c,w):
    if w == c or w == 1:
        return c*r
    d = 0
    if c%w == 0:
        d = -1
    return c/w + d + w
    
def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

