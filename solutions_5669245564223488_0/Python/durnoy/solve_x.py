from __future__ import print_function
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")


T = int(f.readline().strip())

for case_id in range(1, T+1):
    N = int(f.readline().strip())
    cars = list(f.readline().strip().split())
    #~ print(N)
    #~ print(cars)

    car_ids = list(range(0, N))

    # Build char sets.
    char_sets = []
    for i in range(0, N):
        one_char = cars[i][0]
        other_set = set()
        ch1 = one_char
        for ch in cars[i]:
            if ch != ch1:
                ch1 = '0'
                other_set.add(ch)
        char_sets.append({'one_char': one_char, 'other_set': other_set})

    r = [0]

    def go(pos, all_set):
        if pos == N-1:
            train = str.join('', [cars[i] for i in car_ids])
            used = dict()
            prev = ''
            is_ok = True
            for ch in train:
                if ch != prev:
                    prev = ch
                    if ch in used:
                        is_ok = False
                        break
                    used[ch] = True
            if is_ok:
                r[0] += 1
            return
        #
        for i in xrange(pos, N):
            car_ids[pos], car_ids[i] = car_ids[i], car_ids[pos]
            can_go = True
            if pos > 0:
                prev = cars[car_ids[pos-1]]
                cur_info = char_sets[car_ids[pos]]
                if prev[-1] != cur_info['one_char'] and cur_info['one_char'] in all_set:
                    can_go = False
                else:
                    if len(all_set & cur_info['other_set']) > 0:
                        can_go = False
            if can_go:
                new_all = all_set | set(cars[car_ids[pos]])
                go(pos+1, new_all)
            car_ids[i], car_ids[pos] = car_ids[pos], car_ids[i]


    go(0, set())

    print(str.format('Case #{0}: {1}', case_id, r[0]))
