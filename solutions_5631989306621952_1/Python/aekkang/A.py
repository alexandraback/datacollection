# Extract digits from an integer into a set.
def extract(y):
    return set([int(j) for j in str(y)])

# Number of test cases.
T = input()

for i in range(T):
    S = raw_input()
    result = S[0]

    # Use greedy algorithm since you are presented one letter at a time.
    for s in S[1:]:
        if s >= result[0]:
            result = s + result
        else:
            result += s

    print "Case #%d: %s" % (i + 1, result)