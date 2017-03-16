from gcjbase import *
from collections import Counter
from itertools import permutations, combinations_with_replacement

import math

def read_input(filename):
    data = []
    with open(filename, "r") as f:
        cases = read_ints(f)[0]
        # =============================================
        for _ in xrange(cases):
            A, _ = read_ints(f)
            motes = read_ints(f)
            data.append({"A": A, "motes": motes})
        # =============================================
    return data

def make_output(fname, output):
    CASE_PRFX = "Case #%s: "
    fname = fname + time.strftime("%H%M%S") + ".out"
    with open(fname, "w") as f:
        # =============================================
        restext = []
        print "Output content ==============="
        for i, v in enumerate(output):
            line = CASE_PRFX % (i+1,) + str(v) + "\n"
            print line[:-1]
            restext.append(line)
        print "=" * 30
        f.writelines(restext)
        # =============================================

# ----------------------------------------------------------------------

modifications = 0

def additions_to_reach(src, tgt):
    if src == 1:
        return None, None
    no_of_additions = math.log((tgt-1.0)/(src-1.0), 2)
    if no_of_additions < math.ceil(no_of_additions):
        no_of_additions = math.ceil(no_of_additions)
    else:  
        print "banana"
        no_of_additions = math.ceil(no_of_additions) + 1
    result = (2 ** no_of_additions) * (src - 1) + 1
    return no_of_additions, result


def step_impossible(player, motes):
    global modifications
    
    no_of_additions, result_player = additions_to_reach(player, motes[0])
    print "XX", no_of_additions, result_player
    if no_of_additions is not None and no_of_additions < len(motes):
        player = result_player
        modifications += no_of_additions
        return sum_possible(player, motes)
    else:
        modifications += len(motes)
        motes = []
        return player, motes

def sum_possible(player, motes):
    cutoff = 0
    for m in motes:
        if player > m:
            player += m
            cutoff += 1
        else:
            break
    motes = motes[cutoff:]
    return player, motes

@timeit
def solveit(case):
    print case
    global modifications
    modifications = 0
    player = case['A']
    motes = case['motes']
    motes.sort()

    player, motes = sum_possible(player, motes)
    while motes:
        player, motes = step_impossible(player, motes)
    
    return int(modifications)

@timeit
def main(fname):
    data = read_input(fname)
    output = []
    for i, case in enumerate(data):
        statreset() # reset cache stats
        # =============================================
        res = solveit(case)
        output.append(res)
        # =============================================
    make_output(fname, output)


if __name__ == '__main__':
#    main("sample.in")
    #main("test.in")
    main("A-small-attempt2.in")
#main("large.in")