'''
CodeJam Python Lib for Festony, By Festony

Created on 2012-12-12

@author: festony
'''

import time
import threading
from properties import *

__all__ = [ \
           'run_proc', \
           'run_proc_m', \
           'accumulate', \
           ]

print_details = True

def print_detailed_info(info):
    if print_details:
        print info

def run_proc_m(func, input_dividing_func, working_folder=default_working_folder, file_name=default_file_name):
    ''' run_proc multithread version
    '''
    in_path = working_folder + file_name + '.in'
    out_path = working_folder + file_name + '.out'
    inputfile = open(in_path, 'r')
    raw_input_str = inputfile.read()
    inputfile.close()
    input_lines = map(lambda x:x.rstrip('\r\n'), raw_input_str.split('\n'))
    inputs = input_dividing_func(input_lines)
    r = ''
    case_total_num = len(inputs)
    print_detailed_info('{0} cases in total.'.format(case_total_num))
    start_time_overall = time.clock()
    
    ths = []
    for i, func_input in enumerate(inputs):
        ths.append(threading.Thread(target=func,args=(func_input,)))
        ths[i].start()
        
    for i, func_input in enumerate(inputs):
        ths[i].join()
        
    end_time_overall = time.clock()
    print(r)
    print("Overall process time: %g sec(s)" % \
    (end_time_overall - start_time_overall,))
    outputfile = open(out_path, 'w')
    outputfile.write(r)
    outputfile.close()
    return r

def run_proc(func, input_dividing_func, working_folder=default_working_folder, file_name=default_file_name):
    '''Run the function multiple times for cases.
    
    Process time for each run / all runs are tracked.
    1) need to provide the function to process each case, the function
    should take a list as raw func_input;
    2) an input_dividing_func should be provided to break func_input lines into func_input lists
    for each case.
    '''
    in_path = working_folder + file_name + '.in'
    out_path = working_folder + file_name + '.out'
    inputfile = open(in_path, 'r')
    raw_input_str = inputfile.read()
    inputfile.close()
    input_lines = map(lambda x:x.rstrip('\r\n'), raw_input_str.split('\n'))
    inputs = input_dividing_func(input_lines)
    r = ''
    case_total_num = len(inputs)
    print_detailed_info('{0} cases in total.'.format(case_total_num))
    start_time_overall = time.clock()
    
    for i, func_input in enumerate(inputs):
        case_num = i + 1
        print_detailed_info('Case {0}:'.format(case_num))
        start_time_single_case = time.clock()
        r += 'Case #%d: %s\n' % (case_num, str(func(func_input)))
        print_detailed_info("Process time: %g sec(s)" % \
        (time.clock() - start_time_single_case,))
    
    end_time_overall = time.clock()
    print(r)
    print("Overall process time: %g sec(s)" % \
    (end_time_overall - start_time_overall,))
    outputfile = open(out_path, 'w')
    outputfile.write(r)
    outputfile.close()
    return r

# commonly used functions

def accumulate(l):
    r = l[:]
    for i in range(1, len(r)):
        r[i] += r[i-1]
    return r

# Test
if __name__ == '__main__':
    def test_process_func(func_input):
        print 'func_input:', func_input
        return 0
    
    # Set test case input file
    f = open(default_working_folder + default_file_name + '.in', 'r')
    old_content = f.read()
    print old_content
    f.close()
    f = open(default_working_folder + default_file_name + '.in', 'w')
    f.write('''4
5
Yeehaw
NSM
Dont Ask
B9
Googol
10
Yeehaw
Yeehaw
Googol
B9
Googol
NSM
B9
NSM
Dont Ask
Googol
5
Yeehaw
NSM
Dont Ask
B9
Googol
7
Googol
Dont Ask
NSM
NSM
Yeehaw
Yeehaw
Googol
4
Zol
Zolz
Zollz
Zolzz
0
0
3
'AZ'
'BZ'
'CZ'
''')
    f.close()

    def test_input_dividing_func(input_lines):
        total_case = int(input_lines.pop(0))
        case_inputs = []
        for i in range(total_case):
            engine_num = int(input_lines.pop(0))
            engines = input_lines[:engine_num]
            del input_lines[:engine_num]
            query_num = int(input_lines.pop(0))
            queries = input_lines[:query_num]
            del input_lines[:query_num]
            case_inputs.append([engines, queries])
        return case_inputs
    
    run_proc(test_process_func, test_input_dividing_func)
    
    run_proc_m(test_process_func, test_input_dividing_func)
    
    # restore file used in test case back to its original content.
    f = open(default_working_folder + default_file_name + '.in', 'w')
    f.write(old_content)
    f.close()
