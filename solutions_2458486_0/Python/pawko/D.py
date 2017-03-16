# python 3

from collections import Counter
from array import array

MAX_KEY_NR = 200

def process_recur(keys, entry_keys, gain_keys, active_mask, dead_ends):
    if dead_ends[active_mask]:
        return None
#    print('keys: {0}    mask: {1}'.format(keys, bin(active_mask)))
    if active_mask == 0:
        return []
    n = len(entry_keys)
    for idx in range(n):
        if not (active_mask & (1<<idx)):
            continue
#        print('idx {0},  entry_key: {1}'.format(idx, entry_keys[idx]))
        ekey = entry_keys[idx]
        if keys[ekey] == 0:
            continue
#        print('passed, gained: {0}'.format(gain_keys[idx]))

        keys[ekey] -= 1
        for k in gain_keys[idx]:
            keys[k] += 1
        stack = process_recur(keys, entry_keys, gain_keys,
                              active_mask ^ (1<<idx), dead_ends)
        keys[ekey] += 1
        for k in gain_keys[idx]:
            keys[k] -= 1

        if stack is None:
            continue
        stack.append(idx)
#        print('returning stack: {0}'.format(stack))
        return stack
    dead_ends[active_mask] = 1
    return None

def process_case(ini_keys, entry_keys, gain_keys):
    n = len(entry_keys)
    keys = array('I', [0]) * (MAX_KEY_NR + 1)
    for k in ini_keys:
        keys[k] += 1
    active_mask = (1 << n) - 1
    dead_ends = array('B', [0]) * (1<<n)
    stack = process_recur(keys, entry_keys, gain_keys, active_mask, dead_ends)
    if stack is None:
        return 'IMPOSSIBLE'
    result = ' '.join(str(idx+1) for idx in reversed(stack))
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        nkeys,nchests = line_of_numbers(next(lines))
        ini_keys = line_of_numbers(next(lines))
        chdata = [line_of_numbers(next(lines)) for chi in range(nchests)]
        entry_keys = [d[0] for d in chdata]
        gain_keys = [d[2:] for d in chdata]
        result = process_case(ini_keys, entry_keys, gain_keys)
        yield 'Case #{0}: {1}\n'.format(ci, result)
    
def line_of_numbers(s):
    return [int(sub) for sub in s.split()]

def input_gen(f_in):
    for line in f_in:
        if line.endswith('\n'):
            line = line[:-1]
        yield line

def start(basename):
    infile = basename + '.in'
    outfile = basename + '.out'
    f_in = open(infile, 'r')
    f_out = open(outfile, 'w')
    f_out.writelines(result_gen(input_gen(f_in)))
    f_in.close()
    f_out.close()

##start('D-test')
start('D-small-attempt0')
##start('D-large')
