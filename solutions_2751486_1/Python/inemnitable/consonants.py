def substrings(string, n):
    # curr_idx = 0
    queue_start_idx = 0
    cons_start_idx = None
    consec_cons = 0
    substring_sum = 0
    for curr_idx, char in enumerate(string):
        if char not in ['a','i','u','e','o']:
            #print "found cons"
            if cons_start_idx == None:
                cons_start_idx = curr_idx 
            consec_cons += 1
            if consec_cons == n:
                # print "found n cons"
                # print "cons_start_idx " + str(cons_start_idx)
                # print "queue_start_idx " + str(queue_start_idx)
                substring_sum += (len(string) - curr_idx)*(cons_start_idx - queue_start_idx + 1)
                # print "current sum " + str(substring_sum)
                cons_start_idx += 1
                queue_start_idx = cons_start_idx
                consec_cons = curr_idx - cons_start_idx + 1
        else:
            # print "found vowel"
            cons_start_idx = None
            consec_cons = 0
    return substring_sum

t = int(raw_input())
for case in xrange(t):
    name, n = raw_input().split()
    n = int(n)
    print "Case #" + str(case+1) + ": " + str(substrings(name, n))