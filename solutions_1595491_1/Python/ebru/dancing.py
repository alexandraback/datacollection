#==============================================================================
# IMPORTS
#==============================================================================
import sys


#==============================================================================
# FUNCTIONS
#==============================================================================
def split_scores (score_sum):
    base  = score_sum/3
    score = [base for _ in xrange(3)]
    for idx in xrange(score_sum % 3):
        score[idx] += 1
    return score
        
def dancing_max (surprises, min_val, score_sums):
    count  = 0
    scores = []
    for score_sum in score_sums:
        score = split_scores(score_sum)
        if max(score) < min_val:
            scores.append(score)
        else:
            count += 1

    for score in scores:
        if surprises == 0: # no more left for us
            break

        if sum(score) % 3 == 1:
            # can't increase this score without breaking
            # 5 4 4 -> 6 4 3
            continue
        elif (max(score) >= 1 and min_val - max(score) == 1):
            # 5 5 4 -> 6 4 4
            # 5 5 5 -> 6 5 4
            count     += 1
            surprises -= 1

    return count

def read_input_file (filename):
    fh = open(filename, 'r')
    num_tests = fh.readline() # num tests

    tests = []
    for line in fh.readlines():
        line = line.split()
        tests.append([int(i) for i in line])

    return tests

def main (filename):
    for count, test in enumerate(read_input_file(filename)):
        specials = test[1]
        min_val  = test[2]
        sum_scores = test[3:]
        print 'Case #%d: %s' % (count + 1, dancing_max(specials, min_val,
                                                       sum_scores))
        

#==============================================================================
# MAIN
#==============================================================================
if __name__ == '__main__':
    main(sys.argv[1])
