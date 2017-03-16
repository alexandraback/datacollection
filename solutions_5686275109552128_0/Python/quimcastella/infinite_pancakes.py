import sys
import heapq
import math

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            d = int(f.readline())
            ps = map(int, f.readline().split())
            yield case, (d, ps)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def hashed(l):
    out = []
    for i in l:
        if -i > len(out):
            out += [0]*(-i-len(out))
        out[-i-1] += 1
    return str(out)

def problem(d, ps):
    heap = []
    for p in ps:
        heapq.heappush(heap, -p)

    sols = [heap]
    max_steps = - heap[0]
    best = max_steps
    for i in xrange(max_steps):
        next_step = {}
        for h in sols:
            max_value = - heapq.heappop(h)
            if max_value + i < best:
                best = max_value + i 
            if max_value > 3:
                for p in xrange(2, max_value/2 + 1):
                    hsh = hashed(h + [-max_value+p, -p])
                    if hsh in next_step:
                        continue
                    new_h = h[:]
                    heapq.heappush(new_h, -max_value + p)
                    heapq.heappush(new_h, -p)
                    next_step[hsh] = new_h
        sols = next_step.values()
        if not sols:
            break
    return best

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

