import pprint
import operator


def solve(one, two, lvls):
    MAX_REQ = 3000
    goal = len(two) * 2
    n_stars = 0
    n_plays = 0

    lvls.sort(key=lambda (a, b): b * MAX_REQ + a, reverse=True)

    index = sorted(range(len(two)), key=lambda k: two[k])

    one_starred = {}

    print ""

    while lvls:

        # check to see if we can solve the easiest 2-star
        o, t = lvls[-1]
        print n_plays, n_stars, lvls
        if n_stars >= t:
            lvls.pop()
            if len(lvls) in one_starred:
                print "played two-star ({0}, {1}) (1)".format(o, t)
                n_stars += 1
            else:
                print "played two-star ({0}, {1}) (2)".format(o, t)
                n_stars += 2
            n_plays += 1
            continue

        while n_stars < t:
            old_stars = n_stars
            for i in range(len(lvls)):
                a, b = lvls[i]
                if n_stars >= a and i not in one_starred:
                    print "played one-star ({0}, {1}) (2)".format(a, b)
                    one_starred[i] = True
                    n_stars += 1
                    n_plays += 1
                    if n_stars >= t:
                        break
            if old_stars == n_stars:
                return "Too Bad"

    return n_plays


out_fd = open('B-small.out', 'w')
with open('B-small.in') as in_fd:
    t = int(in_fd.readline())
    i = 1
    while in_fd:
        n = in_fd.readline()
        if n == '':
            break
        else:
            n = int(n)
        one, two = [], []
        lvls = []
        for j in range(n):
            a, b = map(int, in_fd.readline().split())
            one.append(a)
            two.append(b)
            lvls.append((a, b))
        solution = solve(one, two, lvls)
        out_fd.write('Case #{0}: {1}\n'.format(i, solution))
        i += 1
out_fd.close()
