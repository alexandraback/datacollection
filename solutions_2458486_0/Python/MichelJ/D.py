# Google Code Jam 2013
# Problem D. Treasure
# mjacquem1

import sys
import logging
import StringIO
import math
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def chest_list(cl):
    res = ""
    for c in cl:
        res += str(c+1) + " "
    return res[:-1]

@echo
def treasure(chest_key_type, keys_in_chest, init_keys):
    my_keys = init_keys
    open_chests = []
    closed_chests = set(xrange(len(chest_key_type)))
    all_res = set()
    for res in tryall(chest_key_type, keys_in_chest, my_keys, open_chests, closed_chests):
        all_res.add(tuple(res))
    if len(all_res)>0:
        return chest_list(min(all_res))
    return "IMPOSSIBLE"

def tryall(chest_key_type, keys_in_chest, my_keys, open_chests, closed_chests):
    if len(closed_chests)==0:
        yield open_chests
    elif len(my_keys)>0:
       # go through all keys that I have
        for key in set(my_keys):
            remaining_keys = my_keys[:]
            remaining_keys.remove(key)
            # go through all open chests with matching key type
            for chest in closed_chests:
                if chest_key_type[chest]==key:
                    # open chest and recurse
                    my_keys_rec = remaining_keys + keys_in_chest[chest]
                    open_chests_rec = open_chests + [chest]
                    closed_chests_rec = closed_chests.copy()
                    closed_chests_rec.remove(chest)
                    for res in tryall(chest_key_type, keys_in_chest, my_keys_rec , open_chests_rec, closed_chests_rec):
                        yield res

def reverse(chest_key_type):
    n_chests = len(chest_key_type)
    key_types = set(chest_key_type)
    return {key_type : [chest for chest in xrange(n_chests) if chest_key_type[chest]==key_type] for key_type in key_types}

def treasure2(chest_key_type, keys_in_chest, init_keys):
    my_keys = init_keys
    open_chests = []
    closed_chests = set(xrange(len(chest_key_type)))
    key_type_chests = reverse(chest_key_type)
    all_res = set()
    for res in tryall2(key_type_chests, keys_in_chest, my_keys, open_chests, closed_chests):
        return chest_list(res)
    return "IMPOSSIBLE"

def chest_key_pairs_in_order(key_type_chests, my_key_set):
    res = sorted([(chest,key) for key in my_key_set for chest in key_type_chests.get(key,[])])
    return res

def enough_keys(key_type_chests, keys_in_chest, my_keys):
    for key,chests in key_type_chests.items():
        nkeys_needed = len(chests)
        nkeys_avail = my_keys.count(key) + sum(keys.count(key) for keys in keys_in_chest)
        if nkeys_avail<nkeys_needed:
            return False
    return True

def unreachable(key_type_chests, keys_in_chest, my_key_set, closed_chests):
    for key,chests in key_type_chests.items():
        if key not in my_key_set:
            for chest in chests:
                nogood = True
                for chest2 in closed_chests:
                    if chest2!=chest:
                        if key in keys_in_chest[chest2]:
                            nogood = False
                if nogood:
                    return True
    return False

def tryall2(key_type_chests, keys_in_chest, my_keys, open_chests, closed_chests):
    if len(closed_chests)==0:
        yield open_chests
    elif len(my_keys)>0 and enough_keys(key_type_chests, keys_in_chest, my_keys) and not unreachable(key_type_chests, keys_in_chest, set(my_keys), closed_chests):
        # go through all keys that I have
        for chest,key in chest_key_pairs_in_order(key_type_chests, set(my_keys)):
            remaining_keys = my_keys[:]
            remaining_keys.remove(key)
            # go through all open chests with matching key type
            # open chest and recurse
            key_type_chests_rec = key_type_chests.copy()
            key_type_chests_rec[key] = key_type_chests[key][:]
            key_type_chests_rec[key].remove(chest)
            my_keys_rec = remaining_keys + keys_in_chest[chest]
            open_chests_rec = open_chests + [chest]
            closed_chests_rec = closed_chests.copy()
            closed_chests_rec.remove(chest)
            for res in tryall2(key_type_chests_rec, keys_in_chest, my_keys_rec , open_chests_rec, closed_chests_rec):
                yield res
    
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (n_init_keys,n_chests) = map(int,raw_input().split(' '))
        init_keys = map(int,raw_input().split(' '))
#        print n_init_keys,n_chests,init_keys
        chest_key_type=[None]*n_chests
        chest_n_keys=[None]*n_chests
        keys_in_chest=[None]*n_chests
        for chest in xrange(n_chests):
            line = map(int,raw_input().split(' '))
            chest_key_type[chest] = line[0]
            chest_n_keys[chest] = line[1]
            keys_in_chest[chest] = line[2:]
#        print chest_key_type, chest_n_keys, keys_in_chest
        print 'Case #%d: %s' % (tc, treasure2(chest_key_type, keys_in_chest, init_keys))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
1 4
1
1 0
1 2 1 3
2 0
3 1 2
3 3
1 1 1
1 0
1 0
1 0
1 1
2
1 1 1
"""

small="""25
2 20
1 3
1 3 2 2 2
3 2 2 2
3 2 3 1
1 1 3
2 2 1 2
2 0
3 1 2
1 0
2 2 1 1
1 1 3
3 1 1
2 0
3 1 3
2 0
3 1 1
1 1 3
1 1 3
1 1 2
3 0
2 2 2 3
3 10
3 6 3
6 2 3 2
2 1 3
3 1 6
3 2 2 5
5 5 4 3 5 6 2
6 1 3
1 3 4 1 6
2 2 2 3
5 3 3 5 4
2 3 3 5 1
23 5
3 1 1 4 2 1 4 1 3 1 2 4 1 1 2 1 3 3 2 4 4 4 4
4 0
2 0
1 1 1
1 3 2 4 3
3 2 3 4
3 5
1 2 1
2 0
2 3 1 1 1
2 1 1
1 1 1
2 1 2
1 1
2
1 3 1 2 3
1 20
13
1 3 7 18 2
18 2 1 11
10 1 16
3 1 9
7 4 10 13 18 6
12 2 4 8
11 1 19
20 4 14 4 4 15
19 2 3 15
15 2 17 5
14 1 12
13 1 20
16 2 8 7
6 1 14
5 2 17 17
4 1 18
17 1 1
8 1 3
2 1 10
9 6 20 2 19 6 1 12
1 1
2
2 3 1 2 3
1 20
11
1 1 11
14 1 1
13 1 14
3 1 13
15 1 3
12 3 1 16 15
7 3 11 12 15
16 1 7
8 1 16
9 2 10 8
18 2 8 9
17 2 18 18
2 1 17
4 1 2
20 2 2 4
10 1 20
6 1 10
5 1 6
19 1 5
11 2 17 19
1 4
1
1 0
1 2 1 3
2 0
3 1 2
3 3
1 1 1
1 0
1 0
1 0
4 20
1 2 4 3
3 0
4 1 3
1 2 4 4
4 1 2
3 3 2 1 3
4 3 2 3 2
4 2 1 3
4 2 1 1
2 5 4 4 1 1 2
1 3 3 2 3
3 0
4 0
3 3 2 4 4
2 1 1
3 1 4
3 1 4
3 2 1 4
1 1 1
3 1 1
4 3 3 1 4
2 9
13 13
13 1 13
13 1 13
13 2 13 13
13 1 13
13 1 13
13 1 13
13 0
13 0
13 0
3 20
3 3 1
3 0
2 1 2
3 1 2
2 2 3 3
1 1 3
3 0
1 0
2 1 1
2 2 3 2
2 1 2
3 1 2
3 0
2 0
2 2 2 1
2 1 1
2 1 3
1 2 2 3
1 4 3 2 3 1
3 0
1 1 1
3 15
2 2 3
3 5 1 3 2 2 3
3 3 2 3 3
3 0
1 0
2 0
1 1 1
3 1 1
3 5 2 2 1 2 1
3 2 3 2
3 1 3
2 3 1 1 1
3 1 1
3 0
3 4 1 2 2 3
2 4 3 2 2 1
3 20
3 2 2
1 1 1
3 0
2 1 1
3 1 3
1 5 2 1 3 1 2
1 3 2 1 2
1 3 2 2 1
3 0
2 0
3 3 3 2 1
1 2 2 2
3 1 1
1 1 1
2 0
3 0
1 1 1
3 2 3 1
2 1 3
2 0
2 2 3 3
1 1
2
2 0
3 10
2 2 2
1 1 2
1 0
1 1 1
1 2 1 2
2 2 1 1
2 0
2 5 2 2 2 1 1
1 2 1 1
1 1 2
2 0
3 19
1 1 1
1 0
1 0
1 0
1 0
1 0
1 0
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 2 1 1
1 2 1 1
1 2 1 1
1 2 1 1
1 1
2
1 1 1
10 20
1 2 3 4 5 6 7 8 9 10
7 1 7
8 0
6 1 6
3 0
9 1 9
1 0
10 0
8 1 8
2 0
5 0
4 1 4
4 0
1 1 1
2 1 2
5 1 5
3 1 3
7 0
9 0
10 1 10
6 0
20 15
5 5 4 4 3 4 1 1 5 3 4 3 5 5 3 1 1 4 1 2
4 0
5 2 2 4
1 1 3
4 2 3 1
5 0
3 3 2 1 3
2 0
5 2 5 3
5 0
4 0
4 2 3 2
5 0
3 3 1 5 3
4 3 2 3 5
3 2 1 1
2 15
1 1
1 1 3
2 1 1
3 2 1 3
2 2 1 3
3 3 2 2 2
1 1 1
3 4 2 1 2 3
3 3 1 2 1
3 2 3 2
3 2 2 2
3 1 2
3 1 1
1 5 2 2 2 2 3
3 4 2 1 2 3
2 3 2 3 3
1 2
2
2 0
2 1 2
1 20
1
3 3 1 1 2
3 1 1
4 1 2
3 0
3 2 3 3
1 0
3 1 1
2 5 1 3 3 1 1
2 0
3 2 1 3
2 1 4
4 2 2 1
1 1 4
4 4 3 4 3 1
4 2 3 2
3 2 3 1
1 1 3
1 4 3 1 2 3
2 2 2 1
3 3 3 3 1
2 13
2 2
2 1 2
2 1 2
2 0
2 0
2 0
2 0
2 1 2
2 2 2 2
2 1 2
2 3 2 2 2
2 0
2 0
2 1 2
"""

small2="""22
2 20
1 3
1 3 2 2 2
3 2 2 2
3 2 3 1
1 1 3
2 2 1 2
2 0
3 1 2
1 0
2 2 1 1
1 1 3
3 1 1
2 0
3 1 3
2 0
3 1 1
1 1 3
1 1 3
1 1 2
3 0
2 2 2 3
3 10
3 6 3
6 2 3 2
2 1 3
3 1 6
3 2 2 5
5 5 4 3 5 6 2
6 1 3
1 3 4 1 6
2 2 2 3
5 3 3 5 4
2 3 3 5 1
23 5
3 1 1 4 2 1 4 1 3 1 2 4 1 1 2 1 3 3 2 4 4 4 4
4 0
2 0
1 1 1
1 3 2 4 3
3 2 3 4
3 5
1 2 1
2 0
2 3 1 1 1
2 1 1
1 1 1
2 1 2
1 1
2
1 3 1 2 3
1 20
13
1 3 7 18 2
18 2 1 11
10 1 16
3 1 9
7 4 10 13 18 6
12 2 4 8
11 1 19
20 4 14 4 4 15
19 2 3 15
15 2 17 5
14 1 12
13 1 20
16 2 8 7
6 1 14
5 2 17 17
4 1 18
17 1 1
8 1 3
2 1 10
9 6 20 2 19 6 1 12
1 1
2
2 3 1 2 3
1 20
11
1 1 11
14 1 1
13 1 14
3 1 13
15 1 3
12 3 1 16 15
7 3 11 12 15
16 1 7
8 1 16
9 2 10 8
18 2 8 9
17 2 18 18
2 1 17
4 1 2
20 2 2 4
10 1 20
6 1 10
5 1 6
19 1 5
11 2 17 19
1 4
1
1 0
1 2 1 3
2 0
3 1 2
3 3
1 1 1
1 0
1 0
1 0
4 20
1 2 4 3
3 0
4 1 3
1 2 4 4
4 1 2
3 3 2 1 3
4 3 2 3 2
4 2 1 3
4 2 1 1
2 5 4 4 1 1 2
1 3 3 2 3
3 0
4 0
3 3 2 4 4
2 1 1
3 1 4
3 1 4
3 2 1 4
1 1 1
3 1 1
4 3 3 1 4
2 9
13 13
13 1 13
13 1 13
13 2 13 13
13 1 13
13 1 13
13 1 13
13 0
13 0
13 0
3 10
2 2 2
1 1 2
1 0
1 1 1
1 2 1 2
2 2 1 1
2 0
2 5 2 2 2 1 1
1 2 1 1
1 1 2
2 0
3 19
1 1 1
1 0
1 0
1 0
1 0
1 0
1 0
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 2 1 1
1 2 1 1
1 2 1 1
1 2 1 1
1 1
2
1 1 1
10 20
1 2 3 4 5 6 7 8 9 10
7 1 7
8 0
6 1 6
3 0
9 1 9
1 0
10 0
8 1 8
2 0
5 0
4 1 4
4 0
1 1 1
2 1 2
5 1 5
3 1 3
7 0
9 0
10 1 10
6 0
20 15
5 5 4 4 3 4 1 1 5 3 4 3 5 5 3 1 1 4 1 2
4 0
5 2 2 4
1 1 3
4 2 3 1
5 0
3 3 2 1 3
2 0
5 2 5 3
5 0
4 0
4 2 3 2
5 0
3 3 1 5 3
4 3 2 3 5
3 2 1 1
2 15
1 1
1 1 3
2 1 1
3 2 1 3
2 2 1 3
3 3 2 2 2
1 1 1
3 4 2 1 2 3
3 3 1 2 1
3 2 3 2
3 2 2 2
3 1 2
3 1 1
1 5 2 2 2 2 3
3 4 2 1 2 3
2 3 2 3 3
1 2
2
2 0
2 1 2
1 20
1
3 3 1 1 2
3 1 1
4 1 2
3 0
3 2 3 3
1 0
3 1 1
2 5 1 3 3 1 1
2 0
3 2 1 3
2 1 4
4 2 2 1
1 1 4
4 4 3 4 3 1
4 2 3 2
3 2 3 1
1 1 3
1 4 3 1 2 3
2 2 2 1
3 3 3 3 1
2 13
2 2
2 1 2
2 1 2
2 0
2 0
2 0
2 0
2 1 2
2 2 2 2
2 1 2
2 3 2 2 2
2 0
2 0
2 1 2
"""

# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
