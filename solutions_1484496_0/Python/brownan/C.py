from itertools import combinations

__author__ = 'Alex Brown'

filename = "C-small-attempt1"
infile = open("{}.in".format(filename))
outfile = open("{}.out".format(filename), 'w')


T = int(infile.readline())
for t in range(1,T+1):
    list = [int(x) for x in infile.readline().strip().split()]
    list.pop(0)
    dict = {}
    done = False
    for i in range(2, len(list)):
        d = {}
        for comb in combinations(list, i):
            if sum(comb) in d:
                set1 = comb
                set2 = d[sum(comb)]
                done = True
                break
            d[sum(comb)] = comb
        if done:
            break

    if not done:
        ans = "\nImpossible"
    else:
        ans = "\n{}\n{}\n".format(" ".join([str(x) for x in set1]), " ".join([str(x) for x in set2]))
    outfile.write("Case #{}:{}".format(t, ans))
    print("Case #{}: {}".format(t, ans))

infile.close()
outfile.close()