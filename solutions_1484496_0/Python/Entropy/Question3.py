
from itertools import combinations
count = 1
for line in open("C-small-attempt1.in","rU").readlines()[1:]:
    line = line.strip().split(" ")[1:]
    line = [int(i) for i in line]
    totals = {}
    end = False
    for i in range(2,20):
        for a in combinations(line,i):
            if sum(a) in (totals):
                print ("Case #"+str(count)+":")
                for x in a:
                    print x,
                print 
                for x in totals[sum(a)]:
                    print x,
                print
                end = True
                break
            else:
                totals[sum(a)] = a
        if end:
            break
    if not end:
        print ("Case #"+str(count)+":") + "Impossible"

    count += 1

