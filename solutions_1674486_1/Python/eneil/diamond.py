#!/usr/bin/env python

input_file = 'diamond-large.dat'

with open (input_file, 'r') as data_file:
    N_tests = int(data_file.readline())
    
    for i in range(0, N_tests):
        N_class = int(data_file.readline())
        inherit = {}
        for j in range(1, N_class+1):
            info = map(int, data_file.readline().split(' '))
            if (info[0] == 0):
                inherit[j] = []
            else:
                inherit[j] = info[1:]
        
        has_diamond = False
        for X in range(1, N_class+1):
            child_list = inherit[X]
            subclass_list = child_list[:]

            while (len(child_list) > 0):
                new_list = []
                for C in child_list:
                    new_list.extend(inherit[C])
                    subclass_list.extend(inherit[C])
                child_list = new_list
                
                # Check for duplicates
                if (len(set(subclass_list)) < len(subclass_list)):
                    has_diamond = True
                    break
        
        if (has_diamond):
            print "Case #{0:d}: Yes".format(i+1)
        else:
            print "Case #{0:d}: No".format(i+1)
                
                
