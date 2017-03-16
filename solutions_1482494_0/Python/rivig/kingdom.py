import sys, string

def kingdom(nlevels, stars_req):
    stars = 0
    moves = 0
    stars_earn = [0] * nlevels
    # pick next move - max stars earned with available stars,
    # harder level better
    best_level = 0
    levels_to_close = nlevels
    while best_level >=0 and levels_to_close:
        max_earn = 0
        best_level = -1
        best_star_play = -1
        best_star_req = -1
        for level in range(nlevels):
            # check 2-star earn first
            stars_to_compete = stars_req[level][1]
            if stars_to_compete >= 0 and stars_to_compete <= stars:
                earn = 2
                if stars_req[level][0] < 0: earn = 1
                if max_earn <= earn and best_star_play < 1 and best_star_req <= stars_to_compete:
                    best_level = level
                    best_star_play = 1
                    best_star_req = stars_to_compete
                    max_earn = earn
                    continue
            # otherwise check 1-star if we already do not have best_stars = 1
            stars_to_compete = stars_req[level][0]
            if stars_to_compete >= 0 and stars_to_compete <= stars:
                earn = 1
                if max_earn <= earn and best_star_play < 0 and best_star_req < stars_to_compete:
                    best_level = level
                    best_star_play = 0
                    best_star_req = stars_to_compete
                    max_earn = earn
        if best_level >= 0:
            # mark as passed
            stars_req[best_level][best_star_play] = -1
            if best_star_play == 1:
#                print "closed level %d" % best_level
                levels_to_close -= 1
            stars += max_earn
            moves += 1
#            print "playing level %d, earning %d, best_star_play %d, total %d" % (best_level, max_earn, best_star_play, stars)
    if levels_to_close == 0:
        return moves
    return "Too Bad"

def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for i in range(ncases):
        line = f.readline().rstrip()
        nlevels = int(line)
        stars = []
        for n in range(nlevels):
            line = f.readline().rstrip()
            nums = map(int, line.split(" "))
            stars.append(nums)
        ans = kingdom(nlevels, stars)
        sys.stdout.write("Case #%d: %s\n" % (i+1, ans))

if __name__ == "__main__":
    main(sys.argv)