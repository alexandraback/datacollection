from codejam import *
import math
import itertools

def read_file(f):
    case = read_int_list(f)
    return case

def solver(case):
    k, c, s = case
    x = math.ceil(k/min(k, c))
    if s < x:
        return 'IMPOSSIBLE'
    if s == k:
        return ' '.join(map(str, range(1, k+1)))
    #output = [0]*(k**c)
    collection = []
    for i in range(k):
        base = ('1'+'0'*i).zfill(k)
        art = base
        for j in range(c-1):
            art = ''.join(map(lambda x: '1'*k if x == '1' else base, art))
        #print(base, art)
        collection.append(art)
##        for n in range(len(art)):
##            if art[n] == '1':
##                output[n] += 1
    for tiles in itertools.combinations(range(k**c), s):
        check_tiles = True
        for art in collection:
            gold = False
            for tile in tiles:
                if art[tile] == '1':
                    gold = True
            if gold == False:
                check_tiles = False
                break
        if check_tiles == True:
            return ' '.join(map(lambda x: str(x+1), tiles))

solve('D-small-attempt1', read_file, solver)
