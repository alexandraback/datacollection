import math
import types

def isTuple(x): return type(x) == types.TupleType

def flatten(T):
    if not isTuple(T): return (T,)
    elif len(T) == 0: return ()
    else: return flatten(T[0]) + flatten(T[1:])

def find_sum(entries):
    sums = {}
    for entry in entries:
        if entry in sums and entry != sums[entry][0]:
            return (entry,), sums[entry]
        
        for x in list(sums.keys()):
            total = x + entry
            concat = (entry,) + sums[x]
            if total in sums and set(concat) != set(sums[total]):
                return concat, sums[total]
            else:
                sums[total] = concat
        sums[entry] = (entry,)
    return None

def sets(f):
    num_entries = int(f.readline())
    for entry_no in range(num_entries):
        entries = [int(x) for x in f.readline().strip().split(' ')]
        count = entries.pop(0)


        print('Case #%d:' % (entry_no+1))
        
        sums = {}
        result = find_sum(entries)
        if result is not None:
            first, second = result
            print(' '.join(str(x) for x in first))
            print(' '.join(str(x) for x in second))
        else:
            print('Impossible')

    f.close()

import sys
sets(open(sys.argv[1]))
