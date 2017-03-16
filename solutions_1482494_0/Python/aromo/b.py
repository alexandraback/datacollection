#!/usr/bin/python
""" template.py < input-file """

def raw_input_words():
    return raw_input().strip().split()

def raw_input_ints():
    return map(int, raw_input_words())

def solve_one():
    N = int(raw_input())
    full_levels = []
    for i in range(N):
        full_levels.append(tuple(raw_input_ints()))

    # this is crucial to avoid wastefully playing half-levels
    full_levels.sort(key=lambda x: - x[1])

    partial_levels = []
    stars = 0
    games = 0

    # print ""
    # print full_levels
    # print ""

    while len(full_levels) + len(partial_levels) > 0:
        # try to do a partial one if possible
        selected = None
        for i in range(len(partial_levels)):
            if partial_levels[i] <= stars:
                selected = i
                break
        if selected is not None:
            # print "Played PARTIAL", partial_levels[selected]
            partial_levels = partial_levels[:selected] + partial_levels[selected+1:]
            stars += 1
            games += 1

        else:
            # try to do a full one if possible 
            selected = None
            for i in range(len(full_levels)):
                if full_levels[i][1] <= stars:
                    selected = i
                    break

            if selected is not None:
                # print "Played", full_levels[selected]
                full_levels = full_levels[:selected] + full_levels[selected+1:]
                stars += 2
                games += 1

            else:
                # try to do a full level for one star
                selected = None
                for i in range(len(full_levels)):
                    if full_levels[i][0] <= stars:
                        selected = i
                        break

                if selected is not None:
                    # print "Played HALF-WAY", full_levels[selected]
                    partial_levels.append(full_levels[selected][1])
                    full_levels = full_levels[:selected] + full_levels[selected+1:]
                    stars += 1
                    games += 1

                else:
                    # totally stuck
                    return "Too Bad"
                           

    return games

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()

