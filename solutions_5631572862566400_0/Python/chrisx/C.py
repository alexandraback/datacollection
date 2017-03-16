from collections import Counter
from random import shuffle

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            N = int(f.readline().split()[0])
            bffs = list(map(int, f.readline().split()))
            sol = solve(N, [None]+bffs)
            # sol = ' '.join(map(str, sol))
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(N, bffs):
    followers = [None]
    for _ in range(N):
        followers.append(set())
    for ind, bff in enumerate(bffs[1:]):
        followers[bff].add(ind+1)

    # find pairs
    pairs = set()
    for i in range(1, N+1):
        if bffs[bffs[i]]==i:
            if i < bffs[i]:
                pair = (i, bffs[i])
            else:
                pair = (bffs[i], i)
            pairs.add(pair)

    pairs_max_len = []
    for pair in pairs:
        pair_len = 2
        for member in pair:
            other = pair[0]+pair[1]-member
            if len(followers[member]) == 1:  # only other
                continue
            assert len(followers[member]) > 1
            follower_max = []
            for follower in followers[member]:
                if follower == other:
                    continue
                follower_max.append(max_chain(followers, follower))
            pair_len += max(follower_max) + 1
        pairs_max_len.append(pair_len)

    if len(pairs) == 0:
        pair_sol = 0
    else:
        pair_sol = sum(pairs_max_len)

    circle_sol = 0
    touched = set()
    order = list(range(1, N+1))
    shuffle(order)
    for i in order:
        if i in touched:
            continue
        touched.add(i)
        this_set = set()
        this_set.add(i)
        number = i
        while bffs[number] not in this_set:
            touched.add(bffs[number])
            number = bffs[number]
            this_set.add(number)
        first_repeat = bffs[number]
        number = first_repeat
        count = 1
        while bffs[number] != first_repeat:
            number = bffs[number]
            count += 1

        circle_sol = max(circle_sol, count)

    return max(pair_sol, circle_sol)





def max_chain(followers, i):
    follower_set = followers[i]
    follower_max = []
    if len(follower_set) == 0:
        return 0
    for follower in follower_set:
        follower_max.append(max_chain(followers, follower))
    return max(follower_max)+1



dir = "./"

'''
input_file = dir+"C-test.txt"
output_file = dir+"C-test.out.txt"
'''

input_file = dir+"C-small-attempt0.in"
output_file = dir+"C-small-attempt0.txt"

'''
input_file = dir+"C-large.in"
output_file = dir+"C-large.txt"
'''

parse(input_file, output_file)



# if everybody has an in, then a bunch of circles.
