#/usr/bin/env python

import sys

import numpy as np

def read_input(filename):
    f = open(filename)
    num_cases = int(f.readline())

    num_with_pancakes = [0]*num_cases
    pancake_lists = [[]]*num_cases
    for i in range(num_cases):
        num_with_pancakes[i] = int(f.readline())
        pancake_lists[i] = [0]*num_with_pancakes[i]
        tmp_list = f.readline().split()
        for j, item in enumerate(tmp_list):
            pancake_lists[i][j] = int(item)

    f.close()
    return num_with_pancakes, pancake_lists

def write_output(filename, num_minutes):
    f = open(filename,'w')

    for i, minutes in enumerate(num_minutes):
        f.write("Case #"+str(i+1)+": "+str(minutes)+"\n")

    f.close()
    return

def get_splits_for_each_diner(pancakes):
    possible_splits = [[0, pancakes]]

    num_splits = 1
    while possible_splits[-1][1] > 3:
        possible_splits.append([num_splits, int(np.ceil(pancakes/(num_splits+1.)))])
        num_splits += 1

    return possible_splits

def get_all_possible_splits(diner_list):
    possible_splits_list = [[]]*len(diner_list)

    for i in range(len(diner_list)):
        possible_splits_list[i] = get_splits_for_each_diner(diner_list[i])

    return possible_splits_list

def get_list_of_stacks_to_split(possible_splits_list, current_splits):
    num_diners = len(possible_splits_list)
    max_value = 0
    for i in range(num_diners):
        if possible_splits_list[i][current_splits[i]][1] > max_value:
            max_value = possible_splits_list[i][current_splits[i]][1]

    split_list = []
    #Return the empty list if the split value is 3 -- no point in further splitting
    #print "    Max: ", max_value
    if max_value <= 3:
        return split_list

    for i in range(num_diners):
        if max_value == possible_splits_list[i][current_splits[i]][1]:
            split_list.append(i)
            
    next_value = max_value - 1
    while next_value > 0 and len(split_list) < len(possible_splits_list):
        num_matches = 0
        
        for i in range(num_diners):
            if next_value == possible_splits_list[i][current_splits[i]][1]:
                split_list.append(i)
                num_matches += 1

        if num_matches == 0:
            break
        elif next_value <= 3:
            #Another case when splitting will do us no good
            return []
        
        next_value -= 1

    return split_list

def get_current_minutes_from_possible_splits(possible_splits_list, current_splits):
    total_num_splits = 0
    max_stack = 0
    num_diners = len(possible_splits_list)

    for i in range(num_diners):
        total_num_splits += possible_splits_list[i][current_splits[i]][0]
        if max_stack < possible_splits_list[i][current_splits[i]][1]:
            max_stack = possible_splits_list[i][current_splits[i]][1]

    return total_num_splits + max_stack

def get_num_minutes(diner_list):
    if max(diner_list) <= 0:
        return 0
    if max(diner_list) == 1:
        return 1
    if max(diner_list) == 2:
        #No point in splitting that pile -- takes 2 steps either way
        return 2
    if max(diner_list) == 3:
        # Splitting or not still takes three steps
        return 3
    
    possible_splits_list = get_all_possible_splits(diner_list)
    old_splits = [0]*len(diner_list)
    old_minutes = get_current_minutes_from_possible_splits(possible_splits_list, old_splits)

    #Do a single initial split
    stacks_to_split = get_list_of_stacks_to_split(possible_splits_list, old_splits)
    #print stacks_to_split
    if len(stacks_to_split) == 0:
        return old_minutes
    new_splits = [0]*len(diner_list)
    for i in range(len(stacks_to_split)):
        new_splits[stacks_to_split[i]] = old_splits[stacks_to_split[i]] + 1
    #print new_splits, diner_list
    #print possible_splits_list
    new_minutes = get_current_minutes_from_possible_splits(possible_splits_list, new_splits)
        
    print "Before loop:", old_minutes, new_minutes
    while new_minutes < old_minutes:
        old_minutes = new_minutes
        #Do additional splits, as they help
        stacks_to_split = get_list_of_stacks_to_split(possible_splits_list, new_splits)
        #print "Splits here: ", stacks_to_split
        if len(stacks_to_split) == 0:
            break
        for i in range(len(stacks_to_split)):
            new_splits[stacks_to_split[i]] = new_splits[stacks_to_split[i]] + 1
        new_minutes = get_current_minutes_from_possible_splits(possible_splits_list, new_splits)
        #print "In the loop:", old_minutes, new_minutes, new_splits

    return min(new_minutes, old_minutes)

def get_num_minutes_all(diner_lists):
    num_minutes = [0]*len(diner_lists)

    for i in range(len(diner_lists)):
        print "Working on case: ", i+1
        num_minutes[i] = get_num_minutes(diner_lists[i])

    return num_minutes

if __name__ == "__main__":
    filename = sys.argv[1]

    num_with_pancakes, pancake_lists = read_input(filename)
    #print "All lists: ", pancake_lists

    num_minutes = get_num_minutes_all(pancake_lists)

    write_output("output.txt", num_minutes)
