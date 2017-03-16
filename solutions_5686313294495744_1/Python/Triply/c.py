

import gurobipy as grb


def find_min_true_topics(topics):
    first_dict = dict()
    second_dict = dict()
    for a, b in topics:
        first_dict[a] = 0
        second_dict[b] = 0
    print 'dict size:', len(first_dict), len(second_dict)
    m = grb.Model()
    topics_var = []
    for a, b in topics:
        var = m.addVar(vtype=grb.GRB.BINARY, name=a + ' ' + b)
        topics_var.append(var)
        first_dict[a] += var
        second_dict[b] += var
    m.update()

    for first_con in first_dict.itervalues():
        m.addConstr(first_con >= 1)
    for second_con in second_dict.itervalues():
        m.addConstr(second_con >= 1)

    m.setObjective(sum(topics_var), grb.GRB.MINIMIZE)
    m.optimize()
    th = 0.5
    return len(topics) -  sum(1 if var.X>th else 0 for var in topics_var)




# INPUT = 'C-small-attempt0.in'
# OUTPUT = 'C-small-attempt0.out'


INPUT = 'C-large.in'
OUTPUT = 'C-large.out'

# INPUT = 'C-test.in'
# OUTPUT = 'C-test.out'


with open(INPUT, 'r') as fin:
    T = int(fin.readline())
    with open(OUTPUT, 'w') as fout:
        for i in xrange(1, T + 1):
            # get input
            N = int(fin.readline())
            topics = []
            for _ in xrange(N):
                a, b = fin.readline().strip().split(' ')
                topics.append((a, b))
            fout.write('Case #{}: {}\n'.format(i, find_min_true_topics(topics)))
