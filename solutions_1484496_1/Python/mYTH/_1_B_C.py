#

import itertools

i = open("C-large.in", "r")
o = open("C-large.out", "w")

T = int(i.readline())

for c in range(1, T + 1):
    args = map(int, i.readline().replace('\n','').split(' '))

    N = args[0]
    SN = args[1:]

    sums, res_sum = {}, -1

    for k in range(1, N):
        sets = itertools.combinations(SN, k)
        for set in sets:
            try:
                sums[sum(set)].append(set)
                res_sum = sum(set)
                break
            except:
                sums[sum(set)] = [set]
        if res_sum != -1:
            break
    
    o.write("Case #{0}:\n".format(c))
    if res_sum == -1:
        o.write("Impossible\n")
    else:
        for res_set in sums[res_sum]:
            o.write(' '.join(map(str, res_set)) + '\n')   

i.close()
o.close()