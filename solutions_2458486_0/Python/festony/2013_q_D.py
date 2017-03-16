'''
CodeJam Practice 
Created on 2013-04-13

@author: festony
'''

from cj_lib import *
from properties import *
import cPickle

#curr_file_name = 'D-large'
curr_file_name = 'D-small-attempt3'
#curr_file_name = 'test'

def copy_state(state):
    p_backup = cPickle.dumps(state)
    state_cp = cPickle.loads(p_backup)
    return state_cp



def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        K, N = map(int, input_lines.pop(0).split(' '))
        keys = map(int, input_lines.pop(0).split(' '))
        dict_keys = dict()
        for k in keys:
            if dict_keys.has_key(k):
                dict_keys[k] += 1
            else:
                dict_keys[k] = 1
        chests = []
        dict_keys_in_chest = dict()
        dict_keys_required = dict()
        dict_keys_total = dict(dict_keys)
        for j in range(N):
            chest_input = map(int, input_lines.pop(0).split(' '))
            chest = [j]
            chest.append(chest_input.pop(0))
            chest.append(chest_input.pop(0))
            chest.append(chest_input)
            chest.append(False) # is already opened?
            chests.append(chest)
            if dict_keys_required.has_key(chest[1]):
                dict_keys_required[chest[1]] += 1
            else:
                dict_keys_required[chest[1]] = 1
            for k in chest[3]:
                if dict_keys_in_chest.has_key(k):
                    dict_keys_in_chest[k] += 1
                else:
                    dict_keys_in_chest[k] = 1
                if dict_keys_total.has_key(k):
                    dict_keys_total[k] += 1
                else:
                    dict_keys_total[k] = 1

        dict_chests = dict()
        for chest in chests:
            if dict_chests.has_key(chest[1]):
                dict_chests[chest[1]].append(chest)
            else:
                dict_chests[chest[1]] = [chest]
        for k in dict_chests.keys():
            dict_chests[k].sort(key=lambda x:x[0])

        case_inputs.append([K, N, dict_keys, dict_chests, dict_keys_in_chest, dict_keys_total, dict_keys_required, chests, []])
    return case_inputs


#orders = []

def check_dead_end(keys, all_locked_chests):
    dict_chests = dict()
    possible_open = set([])
    
    #print "all_locked_chests-",all_locked_chests
    for chest in all_locked_chests:
        if dict_chests.has_key(chest[1]):
            dict_chests[chest[1]].append(chest)
        else:
            dict_chests[chest[1]] = [chest]
    #print "dict_chests-",dict_chests
    
    for k in keys:
        if keys[k] <= 0:
            continue
        possible_open.add(k)
#        for c in dict_chests[k]:
#            for chest in c:
#                for k_in_chest in chest[3]:
#                    possible_open.add(k_in_chest)
    possible_open_len = 0
    while len(possible_open) > possible_open_len:
        l = list(possible_open)
        possible_open_len = len(possible_open)
        for k in l:
            if not dict_chests.has_key(k):
                continue
            for c in dict_chests[k]:
                for k_in_chest in c[3]:
                    possible_open.add(k_in_chest)
    if len(possible_open) < len(dict_chests.keys()):
        return False
    return True

def proc_state_using_key_open_chest(state, key, chest_num):
    order, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests = state
    keys[key] -= 1
    keys_total[key] -= 1
    keys_required[key] -= 1
    order.append(chest_num)
    can_open = chests[key]
    for chest in can_open:
        if chest[0] == chest_num:
            chest[4] = True
            for k in chest[3]:   #got keys
                if keys.has_key(k):
                    keys[k] += 1
                else:
                    keys[k] = 1
                keys_in_chest[k] -= 1
            all_locked_chests.remove(chest)
            all_opened_chests.append(chest)
            break
    #print all_opened_chests
    
    if not check_dead_end(keys, all_locked_chests):
        # dead end
        return []
    return [[order, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests]]

def proc_state_using_key(state, key):
    order, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests = state
    r = []
    #print key
    #keys[key] -= 1
    if chests.has_key(key):
        can_open = chests[key]
        #if key == 4:
            #print '-----------',can_open,'-----------'
        for chest in can_open:
            if not chest[4]:
                r += proc_state_using_key_open_chest(copy_state(state), key, chest[0])
    #if key == 4:
        #print '-----------',r,'-----------'
    return r

def proc_state(state, orders):
    print state
    order, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests = state
    chest_count = 0
    r = []
    #print order
    if len(all_locked_chests) == 0:
        # completed
        orders.append(order[:])
        return r
    #if not check_dead_end(keys, all_locked_chests):
        # dead end
        #return r
    
    sort_keys = []
    for k in keys.keys():
        if keys[k] > 0:
            can_open = []
            if not chests.has_key(k):
                continue
            for c in chests[k]:
                if not c[4]:
                    can_open.append(c[0])
            if len(can_open) == 0:
                continue
            sort_keys.append([k, min(can_open)])
    
    sort_keys.sort(key=lambda x:x[1])
    #print sort_keys

    for k in sort_keys:
        if keys[k[0]] > 0:
            r += proc_state_using_key(copy_state(state), k[0])
    return r

def compx(s1, s2):
    o1 = s1[0]
    o2 = s2[0]
    for i in range(min(len(o1), len(o2))):
        if o1[i] > o2[i]:
            return 1
        if o1[i] < o2[i]:
            return -1
    return 0

#def gene_key_from_order(order, N):
#    #power = range(N)
#    power = []
#    p = 1
#    for i in range(N):
#        power.append(p)
#        p *= 10
#    power.reverse()
#    #print power
#    k = 0
#    for i, o in enumerate(order):
#        k += o * power[i]
#    return k
    
def process_func(func_input):
    #print func_input
    orders = []
    K, N, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests = func_input
    #print sorted(keys.keys())
    for k in keys_required.keys():
        if not keys_total.has_key(k):
            return 'IMPOSSIBLE'
        if keys_total[k] < keys_required[k]:
            return 'IMPOSSIBLE'
            
    order = []
    init_state = [order, keys, chests, keys_in_chest, keys_total, keys_required, all_locked_chests, all_opened_chests]
    states = [init_state]
    while len(states) > 0 and len(orders) == 0:
        state = states.pop(0)
        #print 'in:', state
        #print state
        states += proc_state(state, orders)
        states.sort(cmp=compx)
        #print 'out:', states[0]
        #print 'states len:', len(states)
    if len(orders) == 0:
        return 'IMPOSSIBLE'
    results = []
    for order in orders:
        result = ''
        for i in range(len(order)):
            result += str(order[i] + 1) + ' '
        #print result
        results.append(result)
    return (min(results)).strip()

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#o1 = [1,20]
#o2 = [2]
#x = [o1, o2]
#print sorted(x)
#x = [o2, o1]
#print sorted(x)

#a = [1, 4, [1], [[1, 0, []], [1, 2, [1, 3]], [2, 0, []], [3, 1, [2]]]]
#
#j_backup = cPickle.dumps(a)
#b = cPickle.loads(j_backup)
#
#print a
#print b
#print '-----'
#b[3][0][2].append(4)
#print a
#print b
