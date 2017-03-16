import sys
import itertools
from random import shuffle

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in range(c):
            entries = int(f.readline())
            es = []
            for e in range(entries):
                strs = f.readline().strip().split()
                es.append(strs)
            yield case, (es)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print(s)
    f.write(s + "\n")


def shuffler(array, rep):
    copy = list(array)
    for i in range(rep):
        shuffle(copy)
        yield copy

def problem(es):
    counts_1 = {}
    counts_2 = {}
    adj_1 = {}
    adj_2 = {}
    for w1, w2 in es:
        counts_1[w1] = counts_1.get(w1, 0) + 1
        counts_2[w2] = counts_2.get(w2, 0) + 1
        adj_1.setdefault(w1,[]).append((w1,w2))
        adj_2.setdefault(w2,[]).append((w1,w2))

    new_info = set([])
    candidates = set([])
    out = 0
    for w1, w2 in es:
        if counts_1[w1] > 1 and counts_2[w2] > 1:
            candidates.add((w1,w2))
        else:
            new_info.add((w1,w2))

    counts_1 = {}
    counts_2 = {}
    for w1, w2 in new_info:
        counts_1[w1] = counts_1.get(w1, 0) + 1
        counts_2[w2] = counts_2.get(w2, 0) + 1

    processed = set()
    connected = []
    for w1, w2 in candidates:
        if (w1,w2) in processed:
            continue
        q = [(w1,w2)]
        component = set([(w1,w2)])
        while q:
            c = q.pop()
            if c in processed:
                continue
            processed.add(c)
            for a in adj_1[c[0]]:
                if a not in processed and a not in new_info:
                    q.append(a)
                    component.add(a)
            for a in adj_2[c[1]]:
                if a not in processed and a not in new_info:
                    q.append(a)
                    component.add(a)
        connected.append(component)

    #print(new_info)
    #print(connected)
    #print(list(map(lambda x : len(x), connected)))
    total = 0
    for con in connected:
        best = 0
        if len(con) < 8:
            iterator = itertools.permutations(con)
        else:
            iterator = shuffler(con, 10000)
        for perm in iterator:
            count = 0
            ccounts_1 = {}
            ccounts_2 = {}
            for w1, w2 in perm:
                if counts_1.get(w1,0) + ccounts_1.get(w1,0) >= 1 and counts_2.get(w2,0) +ccounts_2.get(w2,0) >= 1:
                    count += 1
                ccounts_1[w1] = ccounts_1.get(w1, 0) + 1
                ccounts_2[w2] = ccounts_2.get(w2, 0) + 1
            best = max(best,count)
            #print(best)
        total += best
    return total

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

