# Open file.
in_file = open("B-small-attempt0.in", "r")

# Read number of test cases.
test_cases = int(in_file.readline())

# Handle each case.
for case_index in xrange(test_cases):
    tokens = in_file.readline().split()
    googler_count = int(tokens[0])
    suprising_tuples = int(tokens[1])
    min_best_result = int(tokens[2])
    
    #if case_index != 2: continue
    #print "[N: %d | S: %d | p: %d]" % (googler_count, suprising_tuples, min_best_result)
    
    # Determine whether each googler was definitely scored above p
    # or whether they can be if they're a suprising result.
    definitely_above = 0
    suprisingly_above = 0
    for i in xrange(googler_count):
        total_score = int(tokens[3+i])
        tuple = [total_score/3]*3
        remainder = total_score % 3
        for r in xrange(remainder):
            tuple[r] += 1
        #print "- - - " + str(tuple)
        
        # Definitely above?
        if tuple[0] >= min_best_result:
            definitely_above += 1
        # Suprisingly above?
        elif (tuple[0] == tuple[1]) and (tuple[0] + 1 >= min_best_result) and (tuple[1] > 0):
            suprisingly_above += 1
    
    # How many?
    above = definitely_above + min(suprising_tuples, suprisingly_above)
    print "Case #%d: %d" % (case_index + 1, above)