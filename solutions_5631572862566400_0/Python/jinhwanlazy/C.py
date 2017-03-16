from pprint import pprint


def find_circuit(i):
    ret = []
    while True:
        if len(ret) > 0 and ret[0] == i:
            return ret
        elif len(ret) > 1 and ret[-2] == i:
            return ret
        elif i not in ret:
            ret.append(i)
        else:
            return []
        i = BFF[i]
    else:
        return []

def solve():
    circuits = [find_circuit(i) for i in range(N)]
    ans = 0
    for i, c in enumerate(circuits):
        if len(c) >= 2 and BFF[c[-1]] == c[-2] and BFF[c[-2]] == c[-1]:
            for j, c_ in enumerate(circuits):
                if i != j and len(c_) >= 2 and c[-2:] == c_[-2:]:
                    e = min(i, j, key=lambda x: len(circuits[x]))
                    circuits[e] = []
        else:
            ans = max(ans, len(c))
            circuits[i] = []
    if all(not c for c in circuits):
        return ans
    circuits = [c for c in circuits if c]
    for i, c in enumerate(circuits):
        for j, c_ in enumerate(circuits):
            if i != j and c[-2:] == c_[-1:-3:-1]:
                circuits[i] += c_[:-2]
                circuits[j] = []
    ans = max(ans, sum(map(len, circuits)))
    return ans


for case in range(int(input())):
    N = int(input())
    BFF = [int(n)-1 for n in input().split()]
    print('Case #%d:' % (case+1), solve())
