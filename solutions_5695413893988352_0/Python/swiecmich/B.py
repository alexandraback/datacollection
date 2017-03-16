import itertools


t = int(raw_input())
for i in xrange(1, t + 1):
    s = raw_input()
    c, j = s.split()
    def matches(seq, score):
        for k in range(len(seq)):
            if seq[k] != score[k] and score[k] != '?':
                return False
        return True
    c_seq, j_seq = [], []
    for seq in itertools.product("0123456789", repeat=len(c)):
        if matches(seq, c):
            c_seq.append("".join(seq))
        if matches(seq, j):
            j_seq.append("".join(seq))
    #print(c)
    #print(c_seq)
    #print(j)
    #print(j_seq)
    best_diff = 1000000
    best_x = None
    best_y = None
    for x in c_seq:
        for y in j_seq:
            diff = abs(int(x) - int(y))
            #print(x, y, diff)
            if diff < best_diff:
                best_diff = diff
                best_x = x
                best_y = y
            elif diff == best_diff:
                if int(x) < int(best_x):
                    best_x = x
                    best_y = y
                elif int(x) == int(best_x):
                    if int(y) < int(best_y):
                        best_x = x
                        best_y = y
    print "Case #{}: {} {}".format(i, best_x, best_y)
