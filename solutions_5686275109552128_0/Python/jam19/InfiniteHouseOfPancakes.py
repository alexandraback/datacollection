import math

sample = "sample"
small = "B-small-attempt11"
large = "B-large"
current = small

fin = open(current + ".in", "r")
fout = open(current + ".out", 'w')
# f1out = open(current + "1.out", 'w')
# f2out = open(current + "2.out", 'w')

T = int(fin.readline())

# def special(next, seconds):
# if seconds
#
# def pancake(ds):
#     mx = max(ds)
#     next = mx - mx / 2
#      = ds[:]
#     return special(next, seconds)

# def pancakes(vs):

def brute_solve(ds):
    # for x in ds:
    #     if x < 0:
    #         print "ERROR", ds

    if not ds:
        return 0

    m = 0
    mx = max(ds)
    if mx <= 2:
        return mx

    s_ds = ds[:]
    s_ds.remove(mx)

    s_ds.insert(0, mx / 2)
    s_ds.insert(0, mx - mx / 2)

    n_ds = [x - 1 for x in ds if x > 0]

    return 1 + min(brute_solve(s_ds), brute_solve(n_ds))


def solve(N, ds):
    m = 0
    solution = []

    while ds:
        # ds.sort()
        m += 1

        mx = max(ds)
        next = mx - mx / 2

        next_mx = mx
        split_count = next_mx_count = ds.count(mx)

        split_count = 0
        for j, d in enumerate(reversed(ds)):
            if d >= next_mx:
                split_count += 1
                next_mx -= 1

        # seconds = []
        # while True:
        #     seconds = [x for x in ds if mx > x > mx - split_count]
        #     if not seconds:
        #         break
        #     if next_mx == max(seconds):
        #         break
        #     if len(seconds) == next_mx_count:
        #         break
        #     else:
        #         next_mx_count = len(seconds)
        #         split_count = next_mx_count

        #
        # #ls = [math.ceil(math.log(x)) + 1 for x in ds]
        # if len(ds) <= 1:
        #     second = 1
        # else:
        #     second = ds[-2]
        #
        # share = ds[-1] - ds[-1] / 2
        # (mx % 2 == 0) and
        if mx > 2 and mx - next > split_count:
            ds.remove(mx)
            ds.insert(0, next)
            ds.insert(0, mx / 2)
            print mx, ds
        else:
            #m += mx - 1
            #break
            print ds, -1
            for j, d in enumerate(ds):
                ds[j] -= 1
        for k, d in enumerate(ds[:]):
            if d <= 0:
                ds.remove(d)
        if ds:
            solution.append(ds[:])

    # for isol, sol in enumerate(solution):
    #     if max(sol) < m - isol:
    #         print "ERROR", sol, m, isol

    return m


for i in range(T):
    N = int(fin.readline())
    ds = map(int, fin.readline().split())
    candidate = max(ds)
    solution1 = solve(N, ds[:])
    solution = brute_solve(ds)
    if solution > candidate:
        print 'ERROR', i + 1, solution, candidate
    if solution != solution1:
        print 'ERROR', i + 1, solution, solution1, candidate
    answer = "Case #%d: %s\n" % (i + 1, solution)
    print answer
    fout.write(answer)

fin.close()
fout.close()
# f1out.close()
# f2out.close()