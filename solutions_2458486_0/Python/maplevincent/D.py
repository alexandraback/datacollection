from collections import defaultdict

def solve_case(n_keys, n_chests, keys, chest_types, chest_keys):
    mem = defaultdict(dict)
    def solve(keys, chests_left):
        mem_keys = tuple(keys.iteritems())
        mem_chests_left = tuple(chests_left)
        if mem_chests_left in mem[mem_keys]:
            return mem[mem_keys][mem_chests_left]
        
        j = 0
        final_result = None
        while (not final_result) and (j < n_chests):
            if chests_left[j] == 0:
                # not open yet
                chest_type = chest_types[j]
                if keys[chest_type] > 0:
                    #print "opening %d"%(j)
                    chests_left_copy = list(chests_left)
                    chests_left_copy[j] = 1
                    if sum(chests_left_copy) < n_chests:
                        # some chest not open yet
                        keys_copy = keys.copy()
                        keys_copy[chest_type] -= 1
                        for key, n in chest_keys[j]:
                            keys_copy[key] += n
                        result = solve(keys_copy, chests_left_copy)
                        if result != None:
                            final_result = list(result)
                            final_result.append(j)
                        #else:
                            #print "dead end"
                    else:
                        # all chests are open!
                        final_result = [j]
            j += 1
        mem[mem_keys][mem_chests_left] =final_result 
        return final_result

    chests_left = [0]*n_chests
    final = solve(keys, chests_left)
    if final == None:
        r = "IMPOSSIBLE"
    else:
        final = [i+1 for i in final]
        final = reversed(final)
        final = [str(i) for i in final]
        r = ' '.join(final)
    return r

def solve_cases(fin, fout):
    nCases = int(fin.readline().strip())
    for i in xrange(nCases):
        # get case
        n_keys, n_chests = map(int, fin.readline().strip().split())
        keys_list = map(int, fin.readline().strip().split())
        keys = defaultdict(int)
        for key in keys_list:
            keys[key] += 1
            
        chest_types = []
        chest_keys = []
        for j in xrange(n_chests):
            l = map(int, fin.readline().strip().split())
            chest_type = l[0]
            n_keys_in_chest = l[1]
            chest_keys_list = l[2:]
            
            chest_types.append(chest_type)
            d = defaultdict(int)
            for key in chest_keys_list:
                d[key] += 1
            chest_keys.append(list(d.iteritems()))
        # solve case
        result = solve_case(n_keys, n_chests, keys, chest_types, chest_keys)
        fout.write("Case #%d: %s\n"%(i+1, result))
        print "Case #%d: %s\n"%(i+1, result)

from sys import argv
solve_cases(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
