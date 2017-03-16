'''
Created on Apr 13, 2012

@author: karnr
'''
def _recycle_number(n, ll, ul):
    l = list(str(n))
    r = [int("".join(l[i:] + l[:i])) for i in range(1,len(l))]
    f = filter(lambda x: (x != n) and (x >= ll) and (x <= ul), r)
    return f

def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    
    while (count <= num_of_tests):
        test_data[count] = map(int, fh.readline().strip().split())
        count += 1
        
    fh.close()
    return test_data

def _execute_test(test_input):
    test_output = set()
    (start, end) = test_input
    for n in xrange(start, end+1):
        [test_output.add((n,m)) for m in _recycle_number(n, start, end)]
        #print test_output
    print "Done"
    return len(test_output) / 2

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