import sys

in_file = open(sys.argv[1])

num_test_cases = int(in_file.readline().strip())

for i in range(num_test_cases):
    num_levels = int(in_file.readline().strip())
    levels = []
    for j in range(num_levels):
        line = in_file.readline().strip().split(' ')
        entry = [int(x) for x in line]
        levels.append(entry)

    # all levels are complete in this format
    # [ [x1, y1], [x2, y2], .... ]
    # where x is one star, y is two star


    max = 2002
    twos_left = num_levels
    stars = 0
    num_beat = 0
    done = False
    while not done and twos_left > 0:
        # sort by lvl 2s
        can_beat_two = []
        can_beat_one = []
        to_beat = -1

        cur_pos = 0
        while cur_pos < num_levels:
            if stars >= levels[cur_pos][1]:
                if not levels[cur_pos][0] == max:
                    to_beat = cur_pos
                    break
                else:
                    can_beat_two.append(cur_pos)
            elif stars >= levels[cur_pos][0]:
                can_beat_one.append(cur_pos)

            cur_pos += 1

        num_beat += 1
        if not to_beat == -1:
            twos_left -= 1
            stars += 2
            levels[to_beat] = [max, max]
        elif can_beat_two:
            twos_left -= 1
            stars += 1
            levels[can_beat_two[0]][1] = max
        elif can_beat_one:
            max_two = -1
            max_pos = -1
            for one_pos in can_beat_one:
                if max_two < levels[one_pos][1]:
                    max_two = levels[one_pos][1]
                    max_pos = one_pos
            stars += 1
            levels[max_pos][0] = max
        else:
            done = True

    if not twos_left:
        print "Case #%s: %s" % (i+1, num_beat)
    else:
        print "Case #%s: Too Bad" % (i+1, )











