from itertools import product
from collections import defaultdict

def count_occurences(a,b):
    return sum(1 for i in range(len(b)) if b[i:i+len(a)] == a)

def mean(iterable):
    s = 0
    n = 0
    for x in iterable:
        s += x
        n += 1
    return s / n

def solution(K, L, S, keyboard, target):
    possibs = lambda: (''.join(possib) for possib in product(keyboard, repeat = S))
    bananas_to_take = max(count_occurences(target, a) for a in possibs() )
    return bananas_to_take - mean(count_occurences(target, a) for a in possibs())

def parse(inputfilename):
    it = iter(open(inputfilename))
    T = int(next(it))
    for i in range(T):
        line = next(it)
        K,L,S = map(int, line.split())
        keyboard = next(it).strip()
        target = next(it).strip()
        assert (K,L) == (len(keyboard), len(target))
        print("Case #{}: {}".format(i+1, solution(K,L,S,keyboard,target)))

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        parse(sys.argv[1])
    else:
        parse("A-large.in")