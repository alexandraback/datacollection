import sys
import pprint
import copy

def load_tests(filename):
    lines = file(filename).readlines()
    numtests = int(lines[0])
    lines.pop(0)
    tests = []
    while len(lines) > 0:
        x = lines.pop(0)
        a, b = x.split()
        line = lines.pop(0)
        assembly_a = [int(x) for x in line.split()]
        line = lines.pop(0)
        assembly_b = [int(x) for x in line.split()]
        assert int(a) * 2 == len(assembly_a) and int(b) * 2 == len(assembly_b)
            
        tests.append((assembly_a, assembly_b))
        
    return tests

def distance(assembly_a, assembly_b):
    if 0 in (len(assembly_a), len(assembly_b)):
        return 0
    
    toy_num, toy_type = assembly_a[0], assembly_a[1]
    box_num, box_type = assembly_b[0], assembly_b[1]
    
    produced = 0
    
    if toy_type == box_type:
        produced = min(toy_num, box_num)
        toy_num -= produced
        box_num -= produced
        if toy_num == 0:
            assembly_a = assembly_a[2:]
            assembly_b = copy.copy(assembly_b)
            assembly_b[0] = box_num
        else:
            assembly_b = assembly_b[2:]
            assembly_a = copy.copy(assembly_a)
            assembly_a[0] = toy_num
        
        return produced + distance(assembly_a, assembly_b)
    else:
        throw_toys_dist = distance(assembly_a[2:], assembly_b)
        throw_boxes_dist = distance(assembly_a, assembly_b[2:])
        return max(throw_toys_dist, throw_boxes_dist) 
    
def solve(test):
    table = {}
    assembly_a, assembly_b = test
    print distance(copy.copy(assembly_a), copy.copy(assembly_b))
    
def main():
    tests = load_tests(sys.argv[1])
    
    for i in xrange(1, 1 + len(tests)):
        print "Case #%d:" % i, 
        solve(tests[i - 1])

if "__main__" == __name__:
    main()
    