from collections import defaultdict



def main():
    with open('test.out', 'w') as g:
        with open('test.in') as f:
            T = int(f.readline())
            for t in range(T):
                J, P, S, K = map(int, f.readline().strip().split())
                try:
                    assert number(answer(J, P, S, K)) == number(answer2(J, P, S, K))
                except AssertionError:
                    print('AssertionError', J, P, S, K)
                    print('answer1', answer(J, P, S, K))
                    print('answer2', answer2(J, P, S, K))
                    exit(-1)
                answer_str = 'Case #{}: '.format(t + 1) + str(answer2(J, P, S, K))
                print(answer_str)
                g.write(answer_str)
                g.write('\n')


def number(s):
    return s.split('\n')[0]


def answer2(J, P, S, K):
    JP = defaultdict(int)
    PS = defaultdict(int)
    JS = defaultdict(int)
    outfits = 0
    possible = []
    while True:
        least_worn = K + 1
        for j in range(J):
            for p in range(P):
                for s in range(S):
                    if stringify(j, p, s) in possible:
                        continue
                    if worn(JP, JS, PS, j, p, s) < least_worn:
                        least_worn = worn(JP, JS, PS, j, p, s)
                        least_triplet = (j, p, s)
        if least_worn >= K:
            break
        j, p, s = least_triplet
        possible.append(stringify(j, p, s))
        JP[(j, p)] += 1
        PS[(p, s)] += 1
        JS[(j, s)] += 1
        outfits += 1
    return str(outfits) + '\n' + '\n'.join(possible)



def worn(JP, JS, PS, j, p, s):
    return max(JP[(j, p)], PS[(p, s)], JS[(j, s)])


def stringify(j, p, s):
    return str(j + 1) + ' ' + str(p + 1) + ' ' + str(s + 1)

def answer(J, P, S, K):
    JP = defaultdict(int)
    PS = defaultdict(int)
    JS = defaultdict(int)
    outfits = 0
    possible = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                if JP[(j, p)] < K and PS[(p, s)] < K and JS[(j, s)] < K:
                    possible.append(stringify(j, p, s))
                    JP[(j, p)] += 1
                    PS[(p, s)] += 1
                    JS[(j, s)] += 1
                    outfits += 1
    return str(outfits) + '\n' + '\n'.join(possible)


if __name__ == '__main__':
    main()