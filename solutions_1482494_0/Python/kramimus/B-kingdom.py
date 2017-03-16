#!/usr/bin/env python3

import sys

def get_candidate_levels(current_stars, star_lvls, already_won):
    return [i for i, stars in enumerate(star_lvls) if stars <= current_stars and i not in already_won]


def play_game(one_star_lvls, two_star_lvls):
    one_stars_won = set()
    two_stars_won = set()
    current_stars = 0
    plays = 0
    while len(two_star_lvls) > len(two_stars_won):
        candidate_2_stars = get_candidate_levels(current_stars, two_star_lvls, two_stars_won)
        #print("2 stars: %s" % str(candidate_2_stars))
        if candidate_2_stars:
            to_win = candidate_2_stars.pop()
            if to_win in one_stars_won:
                current_stars += 1
            else:
                current_stars += 2
            one_stars_won.add(to_win)
            two_stars_won.add(to_win)
        else:
            candidate_1_stars = get_candidate_levels(current_stars, one_star_lvls, one_stars_won)
            #print("1 stars: %s" % str(candidate_1_stars))
            if not candidate_1_stars:
                return "Too Bad"
            lvl2_stars = [(stars, i) for i, stars in enumerate(two_star_lvls) if i in candidate_1_stars]
            to_win = max(lvl2_stars)[1]
            current_stars += 1
            one_stars_won.add(to_win)
        plays += 1
    return str(plays)

if __name__ == "__main__":
    with open(sys.argv[1]) as f, open(sys.argv[2], "w") as out:
        count = int(f.readline())
        for i in range(1, count + 1):
            nlvl = int(f.readline())
            levels = []
            for j in range(nlvl):
                levels.append(tuple(int(k) for k in f.readline().strip().split()))
            one_stars = [j[0] for j in levels]
            two_stars = [j[1] for j in levels]
            #print(i)
            #print(play_game(one_stars, two_stars))
            out.write("Case #%d: %s\n" % (i, play_game(one_stars, two_stars)))


