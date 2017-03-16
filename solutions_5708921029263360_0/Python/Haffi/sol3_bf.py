# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
import itertools
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    J, P, S, K = [int(x) for x in raw_input().split(" ")]
    triplets = set([])
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
                triplets.add((j,p,s))
    cur_sol = []
    for setsizes in range(1,len(triplets)+1):
        sol_found = False
        counter = 0
        for subsets in itertools.combinations(triplets,setsizes):
            counter += 1
            if counter > 1000000:
                break
            pairdict = {}
            success = True
            for triangles in subsets:
                if not (triangles[0],triangles[1],0) in pairdict:
                    pairdict[(triangles[0],triangles[1],0)] = 1
                else:
                    pairdict[(triangles[0],triangles[1],0)] += 1
                if pairdict[(triangles[0],triangles[1],0)] > K:
                    success = False
                    break
                if not (triangles[0],0,triangles[2]) in pairdict:
                    pairdict[(triangles[0],0,triangles[2])] = 1
                else:
                    pairdict[(triangles[0],0,triangles[2])] += 1
                if pairdict[(triangles[0],0,triangles[2])] > K:
                    success = False
                    break
                if not (0,triangles[1],triangles[2]) in pairdict:
                    pairdict[(0,triangles[1],triangles[2])] = 1
                else:
                    pairdict[(0,triangles[1],triangles[2])] += 1
                if pairdict[(0,triangles[1],triangles[2])] > K:
                    success = False
                    break
            if success:
                cur_sol = subsets
                sol_found = True
                break
        if not sol_found:
            break
    print "Case #{}: {}".format(i, len(cur_sol))
    for t in cur_sol:
        print "{} {} {}".format(t[0], t[1], t[2])
