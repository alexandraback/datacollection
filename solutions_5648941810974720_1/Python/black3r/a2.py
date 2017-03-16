from collections import defaultdict
from sys import setrecursionlimit
import json

setrecursionlimit(10**8)


def contains(a, b):
    for k in b.keys():
        if k not in a:
            return False
        if a[k] < b[k]:
            return False
    return True


def make_dict(str):
    dic = defaultdict(lambda: 0)
    for k in str:
        dic[k] += 1
    return dic


dig_strs = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def make_dicts():
    return [make_dict(k) for k in dig_strs]


def make_list(dic):
    return tuple([(a, dic[a]) for a in dic.keys()])


def make_lists():
    return [make_list(dic) for dic in make_dicts()]

dig_lists = make_lists()


def dic_from_list(list):
    dic = {}
    for c in list:
        a, b = c
        dic[a] = b

    return dic


def subtract(a, b):
    res = {}
    for k in a.keys():
        res[k] = a[k]
    for k in b.keys():
        res[k] -= b[k]
        if res[k] == 0:
            res.pop(k)
    return res


def parse_input(s):
    return make_list(make_dict(s))


def dyncheck(inp):
    dic = dic_from_list(inp)
    counts = {}
    # TWO:
    if "W" in dic and dic["W"]:
        count = dic["W"]
        counts[2] = count
        dic["W"] -= count
        dic["T"] -= count
        dic["O"] -= count
    if "G" in dic and dic["G"]:
        count = dic["G"]
        counts[8] = count
        dic["E"] -= count
        dic["I"] -= count
        dic["G"] -= count
        dic["H"] -= count
        dic["T"] -= count
    if "Z" in dic and dic["Z"]:
        count = dic["Z"]
        counts[0] = count
        dic["Z"] -= count
        dic["E"] -= count
        dic["R"] -= count
        dic["O"] -= count
    if "X" in dic and dic["X"]:
        count = dic["X"]
        counts[6] = count
        dic["S"] -= count
        dic["I"] -= count
        dic["X"] -= count
    if "T" in dic and dic["T"]:
        count = dic["T"]
        counts[3] = count
        dic["T"] -= count
        dic["H"] -= count
        dic["R"] -= count
        dic["E"] -= 2*count
    if "R" in dic and dic["R"]:
        count = dic["R"]
        counts[4] = count
        dic["F"] -= count
        dic["O"] -= count
        dic["U"] -= count
        dic["R"] -= count
    if "F" in dic and dic["F"]:
        count = dic["F"]
        counts[5] = count
        dic["F"] -= count
        dic["I"] -= count
        dic["V"] -= count
        dic["E"] -= count
    if "V" in dic and dic["V"]:
        count = dic["V"]
        counts[7] = count
        dic["S"] -= count
        dic["E"] -= 2*count
        dic["V"] -= count
        dic["N"] -= count
    if "O" in dic and dic["O"]:
        count = dic["O"]
        counts[1] = count
        dic["O"] -= count
        dic["N"] -= count
        dic["E"] -= count
    if "I" in dic and dic["I"]:
        count = dic["I"]
        counts[9] = count

    res = [str(i)*counts[i] for i in range(0, 10) if i in counts]
    return res

T = int(input())
for I in range(1, T+1):
    c = parse_input(input())
    result = ''.join((str(x) for x in sorted(dyncheck(tuple(c)))))
    print("Case #%d: %s" % (I, str(result)))
