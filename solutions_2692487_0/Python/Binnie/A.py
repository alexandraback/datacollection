import sys

def best_moves(armin, motes, ops_done):
    motes.sort(reverse = True)
    while motes != [] and armin > motes[-1]:
        smaller_mote = motes.pop()
        armin += smaller_mote  
    if motes == []: return ops_done
    else:
        remove_motes_score = ops_done + len(motes)
        new_motes = list(motes)
        new_motes.append(armin - 1)
        if armin > 1:
            add_mote_score = best_moves(armin, new_motes, ops_done + 1)
        else:
            add_mote_score = 10**6
        return min(add_mote_score, remove_motes_score)
    

f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    A, N = map(int, f.readline().strip().split())
    motes = map(int, f.readline().strip().split())
    best = best_moves(A, motes, 0)
    print "Case #%d:" % (test + 1), best
