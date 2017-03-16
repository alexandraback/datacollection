import collections

T = int(raw_input())

d2c = {1:"ONE", 2:"TWO", 3:"THREE", 4:"FOUR", 5:"FIVE", 6:"SIX", 7:"SEVEN", 8:"EIGHT", 9:"NINE", 0:"ZERO"}
def count_char(S):
    ccount = collections.Counter()
    for c in S:
        ccount[c] += 1
    return ccount

d2s = {x:count_char(d2c[x]) for x in d2c}

for t in xrange(1, T+1):
    S = raw_input()
    S_ccount = count_char(S)
    result = collections.Counter()
    # count ZERO --> unique Z
    while S_ccount['Z'] > 0:
        S_ccount -= d2s[0]
        result[0] += 1
    # count SIX --> unique X
    while S_ccount['X'] > 0:
        S_ccount -= d2s[6]
        result[6] += 1
    # count TWO --> unique W
    while S_ccount['W'] > 0:
        S_ccount -= d2s[2]
        result[2] += 1
    # count FOUR --> unique U
    while S_ccount['U'] > 0:
        S_ccount -= d2s[4]
        result[4] += 1
    # count EIGHT --> unique G
    while S_ccount['G'] > 0:
        S_ccount -= d2s[8]
        result[8] += 1
    # count THREE --> H is only for EIGHT and THREE, and EIGHT already exhausted
    while S_ccount['H'] > 0:
        S_ccount -= d2s[3]
        result[3] += 1
    # count FIVE --> F is only for FOUR and FIVE, and FOUR already exhausted
    while S_ccount['F'] > 0:
        S_ccount -= d2s[5]
        result[5] += 1
    # count SEVEN --> S is only for SIX and SEVEN, and SIX already exhausted
    while S_ccount['S'] > 0:
        S_ccount -= d2s[7]
        result[7] += 1
    # count NINE --> I is only for FIVE, SIX, EIGHT, and NINE, and FIVE, SIX, EIGHT already exhausted
    while S_ccount['I'] > 0:
        S_ccount -= d2s[9]
        result[9] += 1
    # count ONE --> every other numbers are exhausted
    while S_ccount['O'] > 0:
        S_ccount -= d2s[1]
        result[1] += 1
    solution_str = ''
    for i in xrange(0, 10):
        solution_str += str(i) * result[i]
    print('Case #%d: %s' %(t, solution_str))




