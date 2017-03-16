import sys
sys.setrecursionlimit(3000)

def solve(pairs):
    word_counts1 = dict()
    word_counts2 = dict()
    for i,j in pairs:
        if i not in word_counts1:
            word_counts1[i] = 0
        if j not in word_counts2:
            word_counts2[j] = 0
        word_counts1[i] += 1
        word_counts2[j] += 1
    return solve_helper(pairs, word_counts1, word_counts2)

memoized = dict()

def solve_helper(pairs, word_counts1, word_counts2):
    mem_key = (tuple(pairs), frozenset(word_counts1.items()), frozenset(word_counts2.items()))
    if mem_key in memoized:
        return memoized[mem_key]
    if len(pairs) == 0:
        return 0
    num_faked = 0
    for n,(i,j) in enumerate(pairs):
        if word_counts1[i] == 1 or word_counts2[j] == 1:
            # def not faked
            continue
        # found a possible fake
        word_counts1[i] -= 1
        word_counts2[j] -= 1
        # fake score
        test1 = solve_helper(pairs[n+1:], word_counts1, word_counts2) + 1
        # not fake score
        word_counts1[i] += 1
        word_counts2[j] += 1
        test2 = solve_helper(pairs[n+1:], word_counts1, word_counts2)
        ans = max(test1, test2)
        memoized[mem_key] = ans
        return ans
    return 0
        

with open(sys.argv[1]) as f:
    lines = f.readlines()

T = int(lines[0],10)
line_num = 1
for tt in range(T):
    N = int(lines[line_num],10)
    line_num += 1
    num_copies = 0
    word_pairs = []
    for i in range(N):
        pair = tuple(lines[line_num].strip().split(" "))
        if pair not in word_pairs:
            word_pairs.append(pair)
        else:
            num_copies += 1
        line_num += 1
    #print word_pairs
    assert num_copies == 0
    # group into sets that share the same first word
    # group into sets that share the same second word
    ans = solve(word_pairs)    
    print ("Case #%d:" % (tt+1)), ans

        

