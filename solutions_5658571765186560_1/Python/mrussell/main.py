import fileinput 
from math import ceil

input = fileinput.input()

def print_winner(case_num, who):
    if who == 'R':
        print "Case #%d: RICHARD" % (case_num)
    elif who == 'G':
        print "Case #%d: GABRIEL" % (case_num)
    else:
        assert(False)

def max_shorter_dimension(X): return int(ceil(X / float(2)))

def do_case(case_num):
    [X, R, C] = [int(x) for x in next(input).rstrip().split(' ')]
    if R < C: (R, C) = (C, R) # assume R >= C
    if R * C == 0: print_winner(case_num, 'R'); return
    if (R * C) % X != 0: print_winner(case_num, 'R'); return
    if X > R: print_winner(case_num, 'R'); return # use long skinny one
    max_shorter_dim = max_shorter_dimension(X)
    if max_shorter_dim > C: print_winner(case_num, 'R'); return 
    if C == 1: 
        # Richard wins if he can choose an X-omino where X_r > 1 and X_c > 1
        if X >= 3: 
            print_winner(case_num, 'R'); return
        else: 
            print_winner(case_num, 'G'); return
    # for X >= 7, if R >= 3 and C >= 3, Richard wins by using the hole-in-middle 7-omino
    if X >= 7 and R >= 3 and C >= 3: print_winner(case_num, 'R'); return 
    # If richard can somehow force the R * C grid to be cut into 2 sections where at least one does not have N % X == 0 blocks in, he wins...
    if max_shorter_dim == C:
#        print "in hard case"
        # this is really only for 3, 4, 5, and 6
        assert(X < 7)
#        print "max_shorter_dim %d" % max_shorter_dim
        long_dim = X - max_shorter_dim + 1
#        print "long_dim %d" % long_dim
        # can take up a box of long_dim x max_shorter_dim
        slack_on_long_dim = R - long_dim
        box_area = long_dim * max_shorter_dim
        extra_area = box_area - X
#        print "extra area: %d" % extra_area
        box_breakup_that_wins = False
        for bottom_area in range(1, (extra_area / 2) + 1):
            g_can_place_for_win = False
            for bottom in range(slack_on_long_dim):
                total_bottom_area = bottom_area + bottom * max_shorter_dim
                total_top_area = R * C - X - total_bottom_area
#                print "bottom at %d, bottom area: %d top area: %d" % (bottom, total_bottom_area, total_top_area)
                if total_bottom_area % X == 0 and total_top_area % X == 0: 
                    g_can_place_for_win = True
                    break
            if not g_can_place_for_win: 
                box_breakup_that_wins = True
                break
        if box_breakup_that_wins: print_winner(case_num, 'R'); return
    print_winner(case_num, 'G');
        
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

