directory = 'C:/users/hai/my projects/google code jam/2013/qualification/D/'


def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        print('\n******************** Testcase ', testcase)
        K,N = [int(x) for x in f_in.readline().split()]
        keys = [int(x) for x in f_in.readline().split()]
        assert len(keys) == K
        chests = []
        for i in range(N):
            a = [int(x) for x in f_in.readline().split()]
            T_i = a[0]
            K_i = a[1]
            chests.append([False, a[0],a[2:]])

        solution =  find_way (keys, chests)

        if solution != None:
            f_out.write('Case #' + str(testcase) + ': ' + ' '.join([str(x+1) for x in solution]) + '\n')
        else:
            f_out.write('Case #' + str(testcase) + ': IMPOSSIBLE\n')




def is_there_still_a_way (keys, chests):
    all_keys = list(keys)
    closed_chests = [chst for chst in chests if chst[0] == False]
    for chst in closed_chests:
        all_keys.extend(chst[2])
    chst_types = [chst[1] for chst in closed_chests]
    for chst_type in chst_types:
        if chst_types.count(chst_type) > all_keys.count(chst_type):
            #print ('Not enough keys to open chests of types ', chst_type)
            return False

    #print ('keys = ', sorted(all_keys))
    #print ('chest_types = ', sorted(chst_types))
    
    return True



    
def find_way (keys, chests):


    if not is_there_still_a_way(keys,chests):
        print ('Not enough keys to open chests of specific type')
        return None


    states_reached = set()
    
    maximal_opened_chest = [-1] * (len(chests)+2)
    trail = []

    # get first chest that can be opened
    found = None
    for c in range(len(chests)):
        if chests[c][1] in keys:
            found = c
            break

    if found == None:
        return None

    trail.append(c)

    while trail:
        #print ('Trail :', trail)

        if len(trail) == len(chests):
            # finished!!!!
            return trail

        
        step = len(trail)
        current_chest = trail[-1]
        chests[current_chest][0] = True
        keys.remove(chests[current_chest][1])
        keys.extend(chests[current_chest][2])
        maximal_opened_chest[step] = current_chest
        maximal_opened_chest[step+1] = -1

        states_reached.add(tuple(sorted(trail)))

        next_try = None
        if is_there_still_a_way(keys,chests):
            for c in range(maximal_opened_chest[step+1]+1, len(chests)):
                if (not chests[c][0]) and chests[c][1] in keys:
                    if tuple(sorted(trail+[c])) not in states_reached:
                        next_try = c
                        break

        while next_try == None and len(trail) > 0:
            last_opened_chest = trail.pop()
            chests[last_opened_chest][0] = False
            key_to_reappend = chests[last_opened_chest][1]
            keys_to_remove = chests[last_opened_chest][2]
            
            for ky in keys_to_remove:
                keys.remove(ky)
            keys.append(key_to_reappend)

            step = len(trail)

            next_try = None
            for c in range(maximal_opened_chest[step+1]+1, len(chests)):
                if (not chests[c][0]) and chests[c][1] in keys:
                    if tuple(sorted(trail+[c])) not in states_reached:
                        next_try = c
                        break

        if next_try != None:
            trail.append(next_try)







def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_ctime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()
