INITIAL_CPS = 2.0


def best_strategy(c, f, x):
    cps = INITIAL_CPS
    time = 0.0
    while True:
        wait_for_win = x / cps
        wait_for_farm = c / cps
        cps_with_farm = cps + f
        wait_for_win_with_farm = wait_for_farm + x / cps_with_farm
        if wait_for_win < wait_for_win_with_farm:
            return time + wait_for_win
        else:
            time += wait_for_farm
            cps = cps_with_farm


with open('input') as in_file:
    with open('output', 'w') as out_file:
        num_cases = int(in_file.readline())
        for case in range(num_cases):
            c, f, x = map(float, in_file.readline().split())
            seconds = best_strategy(c, f, x)
            out_file.write('Case #{}: {}\n'.format(case + 1, seconds))
