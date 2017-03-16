from math import ceil

# O_i: the original sequence that is all 'L' except one 'G' at i-th tile.
# F_i: final artwork from O_i (with complexity C)
# We only need to consider cases of {C_i}_{0 <= i < K}.
#   Necessity: obvious;
#   Sufficiency: any original pattern with 'G' at j-th tile must have 'G'
#                anywhere F_j has 'G'.
# F_i has 'G' at j-th tile iff j, written in base K with C digits, has digit i.
#   Let c' be the index of i's first occrence (left to right) in j (base K). Then
#   the triangle that contains this 'G' starts at complexity level c'.
#   Notice j, written in base K, has C digits.
def find(k, c, s):
    if s < ceil(k / c):
        return None
    places = []
    i = j = 0
    while i < k:
        j = k * j + i
        i += 1
        if i % c == 0:
            places.append(j)
            j = 0
    if k % c > 0:
        places.append(j)
    return places

f = open('D-small-attempt0.in', 'r')
o = open('D.out', 'w')

m = int(f.readline().strip())
i = 1

while i <= m:
    k, c, s = list(map(int, next(f).split()))
    places = find(k, c, s)
    if places == None:
        print('Case #{0}: IMPOSSIBLE'.format(i), file = o)
    else:
        one_indexed_str = ' '.join(map(lambda p: str(p + 1), places))
        print('Case #{0}: {1}'.format(i, one_indexed_str), file = o)
    i += 1

f.close()
o.close()
