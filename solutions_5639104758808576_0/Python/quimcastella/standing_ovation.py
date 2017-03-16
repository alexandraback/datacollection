import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            line = f.readline().split()
            smax = line[0]
            s = map(int, list(line[1]))
            yield case, (smax, s)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def problem(smax, s):
    needed_people = 0
    people_standing = 0
    for sl, sp  in enumerate(s):
        if sp == 0: 
            continue
        if sl > people_standing + needed_people:
            needed_people += sl - people_standing - needed_people
        people_standing += sp
    return needed_people

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

