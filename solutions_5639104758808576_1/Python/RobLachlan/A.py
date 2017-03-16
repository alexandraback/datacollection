# Codejam 2015 Q - A, by Robert Lachlan



def extras_needed(shyness_list):
    '''Takes in an array of shynesses.  Outputs the number of extra
    people required.'''
    extras = 0
    standing = 0
    for i in xrange(len(shyness_list)):
        if standing < i and shyness_list[i] > 0:
            extras += i - standing
            standing += i - standing
        standing += shyness_list[i]
    return extras




T = int(raw_input())


for i in xrange(1, T + 1): 
    shyness = map(int, raw_input().split()[1])
    print 'Case #' + str(i) + ':', extras_needed(shyness)
