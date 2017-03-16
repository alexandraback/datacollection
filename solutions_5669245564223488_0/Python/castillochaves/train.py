from collections import defaultdict
from math import factorial as fact
from pprint import pprint


letters = "abcdefghijklmnopqrstuvwxyz"
mod = 1000000007


def solve(file):
    N = int(file.readline())
    trains = file.readline().split()
    trains_by_letter = {l: len([t for t in trains if l in t]) for l in letters}
    min_trains = []
    for t in trains:
        if invalid_train(t, trains_by_letter):
            return "0"
        min_trains.append((t[0], t[-1]))
    #pprint(["".join(t) for t in min_trains])
    starting_letters = defaultdict(lambda: 0)
    ending_letters = defaultdict(lambda: 0)
    repeated_letters = defaultdict(lambda: 0)
    for s, e in min_trains:
        if s == e:
            repeated_letters[s] += 1
        else:
            starting_letters[s] += 1
            ending_letters[e] += 1
    if any([v > 1 for v in starting_letters.values()]):
        return "0"
    if any([v > 1 for v in ending_letters.values()]):
        return "0"
    liberties = N
    ss = set(starting_letters.keys())
    es = set(ending_letters.keys())
    rs = set(repeated_letters.keys())
    liberties -= len(es & ss) + len(rs & (es | ss))
    liberties -= sum([v - 1 for v in repeated_letters.values() if v > 1])
    answer = 1
    #print starting_letters
    #print ending_letters
    #print repeated_letters
    #print liberties
    while liberties > 1:
        answer *= liberties
        answer %= mod
        liberties -= 1
    for v in repeated_letters.values():
        answer *= fact(v) % mod
        answer %= mod
    return "{}".format(answer)


def invalid_train(train, tbl):
    used_letters = []
    last_letter = None
    for l in train:
        if l != last_letter:
            used_letters.append(l)
            last_letter = l
    if len(used_letters) < 3:
        return False
    if len(used_letters) != len(set(used_letters)):
        return True
    middle_letters = (used_letters[1:])[:-1]
    if any(tbl[l] > 1 for l in middle_letters):
        return True


test_answer = {
    1: "1",
    2: "4",
    3: "0",
}


if __name__ == '__main__':
    import sys
    test = False
    try:
        file_name = sys.argv[1]
    except IndexError:
        file_name = 'test.txt'
        test = True
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    with open(file_name) as f:
        T = int(f.readline())
        for i in range(1, T + 1):
            answer = solve(f)
            if test:
                assert answer == test_answer[i]
            else:
                print "Case #%d: %s" % (i, answer)
