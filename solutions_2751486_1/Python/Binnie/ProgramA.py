import sys

vowels = list("aeiou")
consonants = list("bcdfghjklmnpqrstvwxyz")
assert(len(consonants) == 21)

def solve(S, n):
    sub_starts = []
    num_prev_consonants = 0
    for ii in range(len(S)):
        if S[ii] in consonants:
            num_prev_consonants += 1
            if num_prev_consonants >= n:
                sub_starts.append(ii - n + 1)
        else: num_prev_consonants = 0
    if sub_starts == []: return 0
    last_sub_start = sub_starts.pop()
    last_sub_end = last_sub_start + n - 1
    total_subs = 0
    len_S = len(S)
    total_subs += ((last_sub_start + 1) * (len_S - last_sub_end))
    while sub_starts != []:
        start = sub_starts.pop()
        end = start + n - 1
        total_subs += ((start + 1) * (last_sub_end - end))
        last_sub_start = start
        last_sub_end = end
    return total_subs

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    S, n = f.readline().strip().split()
    S = S.strip()
    n = int(n)
    print "Case #%d:" % (t + 1), solve(S, n)
