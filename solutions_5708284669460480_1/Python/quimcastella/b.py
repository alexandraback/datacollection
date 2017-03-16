import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            k, l, s = map(int, f.readline().split())
            keyboard = list(f.readline().strip())
            target = f.readline().strip()
            yield case, (k,l,s, keyboard, target)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def problem(k,l,s,keyboard,target):
    keys = {}
    for i in keyboard:
        keys[i] = keys.get(i,0) + 1
    for t in target: 
        if t not in keys:
            return 0
    if s < l:
        return 0

    pos_beg = s - l + 1
    prob_w = 1
    for t in target:
        prob_w *= keys[t]*1.0/k

    shared = 0
    for i in range(1, l):
        if target[i:] == target[:-i]:
            shared = len(target[i:])
            break
    num_bring = (s - shared)/(l - shared)

    return max(0, num_bring - prob_w*pos_beg)

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

