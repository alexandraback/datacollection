'''
Created on Apr 13, 2012

@author: karnr
'''
def steps_to_grow_size(i, f):
    c = 0
    s = i
    while True:
        if s > f:
            return (s, c)
        
        if (s - 1) == 0:
            return (s, c)
        
        c += 1
        s += s - 1
        
solution_cache = dict()

def _solve_motes(a, motes):
    global solution_cache
    
    print "Solving %s for %s" % (a, motes)
    if (a, motes) in solution_cache:
        print "Solved already"
        return solution_cache[(a, motes)]
    
    if not motes:
        print "Nothing to do now"
        return 0
    
    m = motes[0]
    if a > m:
        print "%s can eat %s, moving ahead" % (a, m)
        steps = _solve_motes(a + m, motes[1:])
        solution_cache[(a, motes)] = steps
        return steps
    
    print "%s can't eat %s, growing its size" % (a, m)
    (newa, gsteps) = steps_to_grow_size(a, m)
    if (gsteps == 0):
        print "Not possible to grow, gave up"
        return 1 + _solve_motes(a, motes[1:])

    print "Grew to size: %s in %s steps" % (newa, gsteps)
    total_steps1 = gsteps + _solve_motes(newa + m, motes[1:])
    print "Case:1 Total steps taken for solving %s with %s : %s" % (a, motes, total_steps1)
    
    total_steps2 = 1 + _solve_motes(a, motes[1:])
    print "Case:2 Total steps taken for solving %s with %s : %s" % (a, motes, total_steps1)
    
    steps = min(total_steps1, total_steps2)
    solution_cache[(a, motes)] = steps
    return steps

def _execute_test(test_input):
    print test_input
    motes = test_input[1]
    motes.sort()
    motes = tuple(motes)
    steps = _solve_motes(test_input[0][0], motes)        
    return steps

def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    lines = fh.readlines()
    while (count <= num_of_tests):
        start_idx = 2 * (count - 1)
        end_idx = start_idx + 2
        test_data[count] = [map(int, l.strip().split()) for l in lines[start_idx: end_idx]]
        count += 1
        
    fh.close()
    
    return test_data

def main():
    test_data_set = _parse_input("test_input")
    num_of_tests = len(test_data_set.keys())
    
    output = open("test_output", "w")
    for test_id in xrange(1, num_of_tests + 1):
        test_data = test_data_set[test_id]
        test_result = _execute_test(test_data)
        output.write("Case #%s: %s\n" % (test_id, test_result))
        
    output.close()
    
if __name__ == '__main__':
    main()