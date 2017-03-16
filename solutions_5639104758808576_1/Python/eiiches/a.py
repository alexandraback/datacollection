# coding: utf-8

import sys

def solve(values):
    n_standing = 0
    n_invited = 0
    for shyness, n_people in enumerate(values):
        if n_people:
            n_to_invite = shyness - n_standing
            if n_to_invite > 0:
                n_invited += n_to_invite
                n_standing += n_people + n_invited
            else:
                n_standing += n_people
    return n_invited

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        smax, shyness_values = fp.readline().strip().split(' ')
        result = solve(map(int, shyness_values))
        print 'Case #{}: {}'.format(t + 1, result)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
