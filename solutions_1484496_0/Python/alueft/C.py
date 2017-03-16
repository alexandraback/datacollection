from itertools import combinations

T = int(raw_input())

for case in range(T):
    print "Case #{0}:".format(case+1)
    dic = {}
    line = raw_input().split()
    nums = [int(i) for i in line[1:]]
    done = False
    for size in range(1,20):
        for i in combinations(range(0,20), size):
            ind = []
            for j in i:
                ind.append(nums[j])
            s = sum(ind)
            if s in dic.keys():
                for k in dic[s]:
                    print k,
                print
                for k in ind:
                    print k,
                print
                done = True
                break
            dic[s] = ind
        if done:
            break
    if not done:
        print "Impossible"
