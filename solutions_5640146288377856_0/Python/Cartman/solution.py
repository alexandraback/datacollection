for case in range(int(raw_input())):
    r, c, w = map(int, raw_input().split())

    n_per_row = c / w
    n_last_row = c / w - 1 - (c % w == 0)
    free_cells = c - n_last_row * w
    last_guesses = free_cells - (free_cells - w - 1) * (free_cells > w)
    total_guesses = (r-1) * n_per_row + n_last_row + last_guesses

    print 'Case #%d: %d' % (case + 1, total_guesses)
