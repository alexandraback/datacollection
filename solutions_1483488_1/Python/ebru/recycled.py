#==============================================================================
# IMPORTS
#==============================================================================
import sys


#==============================================================================
# FUNCTIONS
#==============================================================================
def digits (val):
    return len(str(val)) # easy way

def rotated_vals (val):
    divisors = [10**i for i in xrange(1, digits(val))]
    vals = [val/div + (val % div) * (10**(digits(val) -  digits(div) + 1))
            for div in divisors]
    return vals
        

def recycled (min_val, max_val):
    nums = range(min_val, max_val + 1)
    remain = dict(zip(nums[:], nums[:])) # make a dict for quick lookup

    pairs = 0
    for num in nums:
        if num not in remain:
            continue

        count = 0
        for val in rotated_vals(num):
            if val in remain and val != num:
                remain.pop(val)
                count += 1
        # multiple sets (a,b,c) --> (a,b) (a,c) (b,c)
        pairs += sum(xrange(count+1))
    return pairs

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
        min_val, max_val = test
        print 'Case #%d: %s' % (count + 1, recycled(min_val, max_val))
        

#==============================================================================
# MAIN
#==============================================================================
if __name__ == '__main__':
    main(sys.argv[1])
