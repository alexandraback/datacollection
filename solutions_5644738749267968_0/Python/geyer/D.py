# Deceitful War


def score_DW(n_weights, k_weights):
    n_weights.sort(reverse=True)
    k_weights.sort(reverse=True)
    for n in range(1, len(n_weights) + 1):
        comparison = map(lambda x, y: x > y,
                         n_weights[:n], k_weights[-n:])
        # if all entries are true, Naomi scores at least n points
        if sum(comparison) != n:
            return n-1
    return len(n_weights)


def score_W(n_weights, k_weights):
    n_weights.sort(reverse=True)
    t = k_weights[:]    # copy the list
    t.sort(reverse=True)

    score = 0
    for weight in n_weights:
        if weight > t[0]:
            score = score + 1
            t.pop()
        else:
            t.pop(0)
    return score


with open('D-small-attempt0.in.txt', 'r') as fin, open('D-small.out.txt', 'w') as fout:
    T = int(fin.readline().split()[0])
    print T
    for case in range(1, T + 1):
        fin.readline()  # skip weight number
        line = fin.readline()
        Naomi = map(float, line.split())
        line = fin.readline()
        Ken = map(float, line.split())
        output = "Case #%d: %d %d\n" % (case, score_DW(Naomi, Ken),
                                        score_W(Naomi, Ken))
        fout.write(output)
