# -*- coding: utf-8 -*-

import sys

input_file = open(sys.argv[1], 'r')
output_file = open(sys.argv[2], 'w')

T = int(input_file.readline())
for tt in xrange(T):
    print tt
    N = int(input_file.readline())
    v_dict = {}
    for nn in xrange(N):
        s = input_file.readline()
        v_dict[nn] = set([int(x) -1 for x in s.split()[1:]])

    stop = False
    for nn in xrange(N):
        parents = v_dict[nn]
        b = parents
        while b:
            new_b = set()
            for x in b:
                if parents.intersection(v_dict[x]):
                    stop = True
                    b = False
                    break
                else:
                    parents = parents.union(v_dict[x])
                    new_b = new_b.union(v_dict[x])
            else:
                b = new_b
    if stop:
        output_file.writelines("Case #{0}: {1}\n".format(tt+1, "Yes"))
    else:
        output_file.writelines("Case #{0}: {1}\n".format(tt+1, "No"))