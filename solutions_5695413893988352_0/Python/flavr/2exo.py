def all_scores(n):
    for i in range(10**n):
        yield i


def valid(sc, C):
    sc = str(sc).zfill(len(C))
    for i in range(len(C)):
        if C[i] != '?' and int(sc[i]) != int(C[i]):
            return False
    return True


def score(C, J):
    n = len(C)
    best_scores, current_min = None, 10000

    for sc1 in all_scores(n):
        if not valid(sc1, C):
            continue

        for sc2 in all_scores(n):
            if not valid(sc2, J):
                continue

            if abs(sc1 - sc2) < current_min:
                current_min = abs(sc1 - sc2)
                best_scores = (sc1, sc2)
            elif abs(sc1 - sc2) == current_min:
                if sc1 < best_scores[0]:
                    best_scores = (sc1, sc2)
                elif sc1 == best_scores[0] and sc2 < best_scores[1]:
                    best_scores = (sc1, sc2)

    best_scores = (str(best_scores[0]).zfill(n), str(best_scores[1]).zfill(n))
    return "{} {}".format(*best_scores)


if __name__ == "__main__":
    for i in range(int(input())):
        C, J = input().split()
        print("Case #{}: {}".format(i+1, score(C, J)))
