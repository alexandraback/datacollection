'''
Created on Apr 13, 2012

@author: karnr
'''
from string import maketrans

ii = ' acbedgfihkjmlonqpsrutwvyxz'
oo = ' yfncilwkbouxmeszvdpjrtgahq'
tt = maketrans(oo, ii)

def _parse_input(input_file):
    fh = open(input_file)
    num_of_tests = int(fh.readline().strip())
    count = 1
    test_data = dict()
    
    while (count <= num_of_tests):
        test_data[count] = fh.readline().strip()
        count += 1
        
    fh.close()
    return test_data

def _execute_test(test_input):
    return test_input.translate(tt)

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