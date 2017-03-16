#==============================================================================
# IMPORTS
#==============================================================================
import sys


#==============================================================================
# FUNCTIONS
#==============================================================================
def safety (num, scores):
    total = float(sum(scores))
    num = len(scores)
    answers = [0 for _ in xrange(num)]

    is_safe = lambda x: i > 2*total/num

    non_safe = [i for i in scores if not is_safe(i)]
    non_safe_num = len(non_safe)
    non_safe_tot = float(sum(non_safe))

    for idx, score in enumerate(scores):
        answer = ((total + non_safe_tot)/non_safe_num - score) / total
        answers[idx] = max(0, answer*100)

    return ' '.join(['%f' % i for i in answers])
    

#==============================================================================
# EXECUTE FILE
#==============================================================================
def read_input_file (filename):
    fh = open(filename, 'r')
    num_tests = fh.readline() # num tests

    for line in fh.readlines():
        line = line.split()
        if line == []: break
        if line[0][0] == '#':
            continue
        line = [int(i) for i in line]
        yield (line[0], line[1:])


def main (filename):
    for count, test in enumerate(read_input_file(filename)):
        num, scores = test
        print 'Case #%d: %s' % (count + 1, safety(num, scores))


#==============================================================================
# MAIN
#==============================================================================
if __name__ == '__main__':
    main(sys.argv[1])
