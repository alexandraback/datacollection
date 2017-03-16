def parse(file):
    lines = file.xreadlines()
    next(lines)
    while True:
        try:
            n_levels = int(next(lines).strip())
            levels = [tuple(map(int, next(lines).split())) for i in range(n_levels)]
            yield levels
        except StopIteration:
            break

def init_game(levels):
    return [[False, False] for l in levels]

def push(stars, done, levels):
    for did_level, level in zip(done, levels):
        if did_level[1] or did_level[0]: continue
        
        if level[1] <= stars:
            assert not did_level[0]
            assert not did_level[1]
            did_level[1] = True
            did_level[0] = True
            return stars+2
    for did_level, level in zip(done, levels):
        if did_level[1]: continue
        
        if level[1] <= stars:
            assert did_level[0]
            assert not did_level[1]
            did_level[1] = True
            did_level[0] = True
            return stars+1
    for did_level, level in zip(done, levels):
        if did_level[0] or did_level[1]: continue

        if level[0] <= stars:
            assert not did_level[1]
            assert not did_level[0]
            did_level[0] = True
            return stars+1

    #print stars
    #print done
    #print levels
    return None

if __name__ == '__main__':
    import sys
    for case,levels in enumerate(parse(open(sys.argv[1]))):
        done = init_game(levels)
        stars = 0
        max = len(levels)*2
        rounds = 0
        while True:
            if stars is None:
                print "Case #{}: Too Bad".format(case+1)
                break
            if stars == max:
                assert all(all(l) for l in done)
                print "Case #{}: {}".format(case+1, rounds)
                break
            stars = push(stars, done, levels)
            rounds += 1
