import sys
import bisect
import random


def get_ken(bricks):
    bricks = bricks[:]
    n = len(bricks)

    bricks.sort()

    chosen_naomi = yield

    for round_num in range(n):
        position_of_heavier_brick = bisect.bisect(bricks, chosen_naomi)
        if position_of_heavier_brick == len(bricks):
            position_of_heavier_brick = 0
        chosen_ken = bricks.pop(position_of_heavier_brick)

        chosen_naomi = yield chosen_ken


def get_naomi_honest(bricks):
    for brick in bricks:
        yield brick


def get_naomi_random(bricks):
    bricks = bricks[:]
    random.shuffle(bricks)

    for brick in bricks:
        yield brick


def get_naomi_deceitful(naomis_bricks, kens_bricks):
    bricks = naomis_bricks[:]
    kens_bricks = kens_bricks[:]

    bricks.sort(reverse=True)
    kens_bricks.sort()

    while bricks:
        lightest_kens_brick = kens_bricks[0]
        heaviest_kens_brick = kens_bricks[-1]

        lightest_brick = bricks.pop()
        if lightest_kens_brick < lightest_brick:
            chosen_ken = yield heaviest_kens_brick + 1e-7
        else:
            chosen_ken = yield heaviest_kens_brick - 1e-7

        kens_bricks.remove(chosen_ken)


def simulate_war(naomi, ken):
    score_naomi = 0

    chosen_naomi = naomi.next()
    ken.next()

    while True:
        try:
            chosen_ken = ken.send(chosen_naomi)
            #print 'Naomi %s. Naomi %.5f, Ken responded with %.5f' % ('wins' if chosen_naomi > chosen_ken else 'looses', chosen_naomi, chosen_ken)
            if chosen_naomi > chosen_ken:
                score_naomi += 1
            chosen_naomi = naomi.send(chosen_ken)
        except StopIteration:
            break

    #print 'GAME OVER. Total Naomi score: %d' % score_naomi
    return score_naomi


def get_scores(n, naomis, kens):
    score_deceitful = simulate_war(get_naomi_deceitful(naomis, kens), get_ken(kens))
    score_honest = simulate_war(get_naomi_honest(naomis), get_ken(kens))
    return score_deceitful, score_honest


def read_test_case(fp):
    n = int(fp.readline())
    naomis = map(float, fp.readline().split(' '))
    kens = map(float, fp.readline().split(' '))
    return n, naomis, kens


def read_input(path):
    with open(path) as fp:
        ncases = int(fp.readline())
        for i in range(ncases):
            yield read_test_case(fp)


def print_case_result(n, answer, out_fp):
    score_deceitful, score_honest = answer
    out_fp.write('Case #%d: %d %d\n' % (n, score_deceitful, score_honest))


if __name__ == '__main__':
    answer_getter = get_scores
    input_path = sys.argv[1]
    if len(sys.argv) == 3:
        output_path = sys.argv[2]
        out_fp = open(output_path, 'w')
    else:
        out_fp = sys.stdout
    for i, test_case in enumerate(read_input(input_path)):
        print_case_result(i + 1, answer_getter(*test_case), out_fp)
