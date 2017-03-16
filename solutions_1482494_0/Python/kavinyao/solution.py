def minimal_play_times(levels, setting):
    played_times = 0
    current_stars = 0
    incomplete_levels = set(range(levels))
    rated_1star_levels = set()

    while len(incomplete_levels) > 0:
        # first try play 2 stars rating
        capable_play_2star_levels = [l for l in incomplete_levels if setting[l][1] <= current_stars]
        if len(capable_play_2star_levels) > 0:
            level_to_play = capable_play_2star_levels[0]
            if level_to_play in rated_1star_levels:
                current_stars += 1
            else:
                current_stars += 2
            incomplete_levels.remove(level_to_play)
            played_times += 1
            continue

        # no 2 stars available to play
        # try 1 star rating
        capable_play_1star_levels = [l for l in incomplete_levels if setting[l][0] <= current_stars]
        if len(capable_play_1star_levels) > 0:
            level_to_play = capable_play_1star_levels[0]
            current_stars += 1
            rated_1star_levels.add(level_to_play)
            played_times += 1
            continue

        # no more choices, but still have have levels to complete
        # Too Bad
        return -1

    return played_times

if __name__ == '__main__':
    import sys
    input_file_name = sys.argv[1]
    with open(sys.argv[1]) as input_file:
        cases_num = int(input_file.next())
        with open('result', 'wb') as output_file:
            for i in range(cases_num):
                print 'solving case %d' % (i+1)
                A = int(input_file.next())
                setting = []
                for j in range(A):
                    setting.append([int(x) for x in input_file.next().split(' ')])
                mt = minimal_play_times(A, setting)
                if mt < 0:
                    output_file.write("Case #%s: Too Bad\n" % (i+1))
                else:
                    output_file.write("Case #%s: %d\n" % (i+1, mt))
