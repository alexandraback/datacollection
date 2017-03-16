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
#        print "max_shorter_dim %d" % max_shorter_dim
        long_dim = X - max_shorter_dim + 1
#        print "long_dim %d" % long_dim
        slack_on_long_dim = R - long_dim
        short_dim_that_wins = False
        # where should we stick out the short dim?
        for short_dim_sticking_out_from in range(2, int(ceil(long_dim / float(2))) + 1):
#            print "trying short_dim_sticking_out_from %d" % short_dim_sticking_out_from
            g_can_place_for_win = False
            # does there exist a bottom position s.t. G wins?
#            print "slack_on_long_dim: %d" % slack_on_long_dim
            for bottom in range(slack_on_long_dim):
                # area of bottom potion
                bottom_area = bottom * C + (max_shorter_dim - 1) * (short_dim_sticking_out_from - 1)
                top_area = R * C - bottom_area - X
                if bottom_area % X == 0 and top_area % X == 0: 
                    g_can_place_for_win = True
                    break
            if not g_can_place_for_win: 
                short_dim_that_wins = True
                break
        if short_dim_that_wins: print_winner(case_num, 'R'); return
    print_winner(case_num, 'G');
        
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

