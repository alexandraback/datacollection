#!/usr/bin/python

import sys, pdb

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def trace(*strs):
    return
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            trace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            trace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

class Answer:
    def __init__(self, s):
        self.s = s

class Bag:
    def __init__(self, members):
        self.counts = {}
        for x in members:
            self.add_member(x)

    def __str__(self):
        pieces = []
        for (member, count) in self.counts.items():
            assert count >= 0
            if count > 0:
                pieces.append('%s: %d' % (member, count))
        return '{' + ', '.join(pieces) + '}'

    def copy(self):
        c = Bag([])
        c.counts = self.counts.copy()
        return c

    def is_empty(self):
        for (member, count) in self.counts.items():
            assert count >= 0
            if count > 0: return False
        return True

    def add_member(self, x, quantity=1):
        if x in self.counts:
            self.counts[x] += quantity
        else:
            self.counts[x] = quantity

    def add_bag(self, b):
        for (key, num) in b.counts.items():
            self.add_member(key, num)

    def remove(self, x):
        assert self.counts[x] > 0
        self.counts[x] -= 1

    def count(self, x):
        return self.counts.get(x, 0)

class Chest:
    def __init__(self, number, opening_key, keys_inside):
        self.number = number
        self.opening_key = opening_key
        self.keys_inside = Bag(keys_inside)

# ---------------------------------------------------------

def read_and_do_case():
    (n_starting_keys, n_chests) = map(int, getline().split())
    starting_keys = map(int, getline().split())
    assert len(starting_keys) == n_starting_keys

    all_chests = []
    for i in range(n_chests):
        d = map(int, getline().split())
        opening_key = d[0]
        n_keys_inside = d[1]
        keys_inside = d[2:]
        assert len(keys_inside) == n_keys_inside
        all_chests.append( Chest(i+1, opening_key, keys_inside) )

    if 0:
        if case_num != 13:
            trace('skip')
            continue

        trace(n_starting_keys, 'starting key(s):', starting_keys)
        trace(n_chests, 'chests:')
        for chest in all_chests:
            trace()
            trace('    number:', chest.number)
            trace('    opening_key:', chest.opening_key)
            trace('    keys_inside:', str(chest.keys_inside))

    starting_keys = Bag(starting_keys)

    # check the endpoint
    try:
        check_keys_in_hand = starting_keys.copy()
        for chest in all_chests:
            # add the keys inside the chest:
            check_keys_in_hand.add_bag(chest.keys_inside)
        for chest in all_chests:
            # use the key to open the chest:
            check_keys_in_hand.remove(chest.opening_key)
    except AssertionError:
        return "IMPOSSIBLE"

    trace(check_keys_in_hand)

    dead_ends = set()

    def search(nums_of_opened_chests, unopened_chests, keys_in_hand):
        # nums_of_opened_chests are in order of opening
        # unopened_chests are in lexico order
        # keys_in_hand is a Bag of keys
        indent = '  ' * len(nums_of_opened_chests)
        trace()
        trace(indent, nums_of_opened_chests, keys_in_hand)

        if unopened_chests == []:
            raise Answer(' '.join(map(str,nums_of_opened_chests)))
        else:
            set_of_opened_chests = frozenset(nums_of_opened_chests)
            if set_of_opened_chests in dead_ends:
                trace(indent, "abort because this set of opened chests is a known dead-end")
                return

            if keys_in_hand.is_empty():
                trace(indent, 'add to dead ends because no keys in hand:', set_of_opened_chests)
                dead_ends.add(set_of_opened_chests)
                return

            # if len(nums_of_opened_chests) == 13: pdb.set_trace()

            for (i,chest) in enumerate(unopened_chests):
                # Try a solution in which this is the next chest to open.

                # Do we have a key that will open this chest?
                if keys_in_hand.count(chest.opening_key) > 0:
                    # Yes we do.

                    resulting_keys = keys_in_hand.copy()
                    # use the key to open the chest:
                    resulting_keys.remove(chest.opening_key)
                    # add the keys inside the chest:
                    resulting_keys.add_bag(chest.keys_inside)

                    search(
                        nums_of_opened_chests + [chest.number], 
                        unopened_chests[:i] + unopened_chests[i+1:],
                        resulting_keys
                    )
                else:
                    # No we don't.
                    pass

            # If control reaches here,
            # then there was no call to search() that eventually found a solution.
            # I.e., this state does not lead to a solution.
            # 
            # The current state is characterized by the *set* of opened chests.
            # That is, any permutation of $nums_of_opened_chests would either
            # have been illegal or it would end up with the same keys_in_hand.
            # Therefore, we can say that this set of opened chests does not
            # lead to a solution.
            trace(indent, 'add to dead ends:', set_of_opened_chests)
            dead_ends.add(set_of_opened_chests)


    try:
        search([], all_chests, starting_keys)
    except Answer, a:
        return a.s

    return "IMPOSSIBLE"


n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    result = read_and_do_case()

    print 'Case #%d: %s' % (case_num, result)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
