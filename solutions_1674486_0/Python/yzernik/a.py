from collections import deque as Queue


def solve(cl):
    counted = set()
    inh = [set() for c in cl]
    while len(counted) != len(inh):
        for i in range(len(cl)):
            if i+1 not in counted and len([c for c in cl[i] if c not in counted]) == 0:
                for j in range(len(cl[i])):
                    if cl[i][j] in inh[i]:
                        return 'Yes'
                    else:
                        inh[i].add(cl[i][j])
                    for k in inh[cl[i][j]-1]:
                        if k in inh[i]:
                            return 'Yes'
                        else:
                            inh[i].add(k)
                counted.add(i+1)
    return 'No'


inp = raw_input()
T = int(inp)
for t in range(1,T+1):
    inp = raw_input()
    N = int(inp)
    classes = []
    for i in range(1,N+1):
        inp = raw_input()
        c = map(int,inp.split(' '))[1:]
        classes.append(c)
    answer = solve(classes)
    print "Case #" + str(t) + ": " + str(answer)
