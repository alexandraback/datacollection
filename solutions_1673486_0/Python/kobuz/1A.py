T = int(raw_input())
for i in range(T):
    A, B = map(int, raw_input().split())
    p_letter = map(float, raw_input().split())
    pmax = 0.0

    # keep typing
    all_correct = 1.0
    for p in p_letter:
        all_correct *= p
    ev_all_correct = all_correct * (B - A + 1) + (1 - all_correct) * (2 * B - A + 2)

    # right away
    ev_right_away = B + 2
    
    # backspace
    # retype all
    ev_backspace = A + B + 1
    correct = 1.0
    for pos in xrange(1, A):
        backspaces = A - pos
        correct *= p_letter[pos - 1]
        ev_tmp = correct * (B - A + 2 * backspaces + 1) + (1 - correct) * (2 * B - A + 2 * backspaces + 2)
        ev_backspace = min(ev_backspace, ev_tmp)

    print "Case #%d: %.6f" % (i + 1, min(ev_all_correct, ev_right_away, ev_backspace))

