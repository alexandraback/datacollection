def solve(N, lists):
    first = {}
    second = {}
    fakes = []
    for l in lists:
        t = l[0]
        if t not in first:
            first[t] = 0
        first[t] += 1
        t = l[1]
        if t not in second:
            second[t] = 0
        second[t] += 1
        fakes.append(l)
    real = 0
    for l in lists:
        if first[l[0]] == 1 or second[l[1]] == 1:
            real += 1
            fakes.remove(l)
    fake = 0 # fake for sure
    while len(fakes) > 0:
        f = fakes.pop()
        fake += 1
        first[f[0]] -= 1
        second[f[1]] -= 1
        for t in list(fakes):
            if first[t[0]] == 1 or second[t[1]] == 1:
                real += 1
                fakes.remove(t)
    return len(lists) - real

# def solve(N, lists):
#     first = {}
#     second = {}
#     for l in lists:
#         t = l[0]
#         if t not in first:
#             first[t] = 0
#         first[t] += 1
#         t = l[1]
#         if t not in second:
#             second[t] = 0
#         second[t] += 1
#     real = 0
#     for l in lists:
#         if first[l[0]] == 1 or second[l[1]] == 1:
#             real += 1
#     return len(lists) - real

with open('third.in', 'r') as fin:
    with open('third.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            N = int(fin.readline())
            lists = [fin.readline().rstrip().split(' ') for tt in range(N)]
            fout.write('Case #{0}: {1}\n'.format(i, solve(N, lists)))
