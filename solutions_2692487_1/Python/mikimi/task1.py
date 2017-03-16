import sys

T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    [A, N] = map(int, sys.stdin.readline().split())
    motes = map(int, sys.stdin.readline().split())
    #print "testcase:", A, N, motes
    motes.sort()
    best_result = len(motes)+1
    curr_added = 0
    for i, v in enumerate(motes):
        #print (i, v)
        if A > v:
            A+=v
        else:
            #albo rezydnujemy:
            best_result = min(best_result, curr_added + len(motes)-i)
            #print "new best_result:", best_result
            #albo dodajemy sobie o jeden mniejsze dopoki sa mniejsze:
            if A == 1:
                curr_added = best_result
                break
            while A <= v:
                curr_added += 1
                A += A-1
            A += v
            #print "curr_added, A:", curr_added, A
    result = min(best_result, curr_added)
    
    print "Case #"+str(case)+": "+str(result)
