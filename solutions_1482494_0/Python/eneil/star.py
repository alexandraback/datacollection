#!/usr/bin/env/python

input_file = 'star-small.dat'

with open (input_file, 'r') as data_file:
    N_tests = int(data_file.readline())
    
    for i in range(0, N_tests):
        N_levels = int(data_file.readline())
        lev_1S = []
        lev_2S = []

        lev_tuples = []

        for j in range(0, N_levels):
            (L1, L2) = map(int, data_file.readline().split(' '))
            lev_1S.append(L1)
            lev_2S.append(L2)
            lev_tuples.append( (L1,L2) )
                    
        # Check for impossibility
        all_levels = lev_1S[:]
        all_levels.extend(lev_2S)
        all_levels.sort()
        
        impossible = False
        for index in range(0,len(all_levels)):
            if (all_levels[index] > index):
                impossible = True
        
        if (impossible):
            print "Case #{0:d}: Too Bad".format(i+1)
            continue

        # If possible, default best case is all 2-star levels only
        total_1S = 0
        bonus_1S = 0
        pair_2S = []
        lev_2S.sort()
        lev_tuples.sort(key=lambda (L1,L2): -(L2-L1))

        for k in range(0,N_levels-1):
            N_star = (2*k + bonus_1S)
            delta = lev_2S[k] - N_star
            
            # Check if we're losing a 1-star bonus
            if (lev_2S[k+1] > lev_2S[k]):
                while (lev_2S[k] in pair_2S):
                    pair_2S.remove(lev_2S[k])
                    bonus_1S = bonus_1S - 1
            
            if (delta > 0):
                # Go through the tuples and "play" 1-star levels to make up delta
                count_1S = 0
                while (count_1S < delta):
                    for tuple in lev_tuples:
                        if tuple[0] <= (N_star + count_1S) and tuple[1] >= lev_2S[k]:
                            pair_2S.append(tuple[1])
                            lev_tuples.remove(tuple)
                            count_1S = count_1S + 1
                            
                            break
                    
                bonus_1S = bonus_1S + delta
                total_1S = total_1S + delta
        

        # Edge case - if we need one star on the very last level that I didn't include
        # in the loop above
        last_2S = sorted(lev_2S)[-1]
        last_1S = sorted(lev_1S)[-1]

        if (last_2S == 2*N_levels - 1 and last_1S == 2*N_levels - 2):
            total_1S = total_1S + 1
                
        print "Case #{0:d}: {1:d}".format(i+1, N_levels + total_1S)
        