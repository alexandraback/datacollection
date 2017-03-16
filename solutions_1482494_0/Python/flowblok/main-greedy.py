# bfs

# state == ({ones}, {twos}, score, nplayed)

# a level pair is (i, j), where i is the level #,
# and j is the j-star rating of that level

n_cases = int(raw_input())

for case in xrange(1, n_cases + 1):
    ones, twos = zip(*[
        tuple(map(int, raw_input().split()))
        for i in xrange(int(raw_input()))
    ])
    n_levels = len(ones)

    result = float('infinity')
    initial_state = ((), (), 0, 0)

    todo = [initial_state]
    done = set(todo)
    while todo:
        ones_done, twos_done, score, nplayed = todo.pop(0)
        if len(twos_done) == n_levels:
            result = nplayed
            break

        # make mutable
        ones_done = list(ones_done)
        twos_done = list(twos_done)

        # greedy: see if there are any two-stars we can do
        found_any = False
        keep_loopin = True
        while keep_loopin:
            keep_loopin = False
            for i, needed in enumerate(twos):
                if i in twos_done:
                    continue

                if needed <= score:
                    nplayed += 1
                    if i not in ones_done:
                        score += 1
                        ones_done.append(i)
                    score += 1
                    twos_done.append(i)
                    keep_loopin = True
                    found_any = True

        # make immutable
        ones_done = tuple(ones_done)
        twos_done = tuple(twos_done)

        if found_any:
            state = (ones_done, twos_done, score, nplayed)
            if state not in done:
                todo.append(state)
                done.add(state)
            todo.sort(key=lambda x: x[3])
            continue

        # try playing each ones
        for i, needed in enumerate(ones):
            if needed > score:
                continue
            state = (
                ones_done + (i,),
                twos_done,
                score + 1,
                nplayed + 1,
            )
            if state not in done:
                todo.append(state)
                done.add(state)
        todo.sort(key=lambda x: x[3])

    if result == float('infinity'):
        result = 'Not Bad'
    print 'Case #%d: %s' % (case, result)
