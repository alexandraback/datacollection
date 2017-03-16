from functools import wraps
import time
import os

###############################
##      useful decorators
###############################

# a decorator for memoizing function outputs
def memoize_it(inner_func):
    global __memoization_registry
    try:
        __memoization_registry
    except NameError:
        __memoization_registry = []
    cache = {}
    __memoization_registry.append(cache)
    @wraps(inner_func)
    def wrap(*args):
        if args not in cache:
            cache[args] = inner_func(*args)
        return cache[args]
    return wrap

# clear all previous memoization. For use in the beginning of a new test-case
def reset_memoization ():
    global __memoization_registry
    try:
        for cache_d in __memoization_registry:
            cache_d.clear()
    except NameError:
        pass
        
# a decorator for adding printing of timing for a function
def time_it(inner_func):
    @wraps(inner_func)
    def wrap(*args):
        print ('--> Start function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        starttime = time.time()
        res = inner_func(*args)
        endtime = time.time()
        print ('--> End   function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        print ('--> Elapsed time \'' + inner_func.__qualname__ + '\' : ', endtime-starttime)
        print()
        return res
    return wrap
    
# a decorator for counting the number of calls to the wrapped function
def count_it (inner_func):
    global _CALL_FUNC_COUNTERS
    if '_CALL_FUNC_COUNTERS' not in globals():
        _CALL_FUNC_COUNTERS = {}
    assert type(_CALL_FUNC_COUNTERS) == dict
    assert inner_func.__qualname__ not in _CALL_FUNC_COUNTERS
    _CALL_FUNC_COUNTERS[inner_func.__qualname__] = 0
    @wraps(inner_func)
    def wrap(*args):
        global _CALL_FUNC_COUNTERS
        _CALL_FUNC_COUNTERS[inner_func.__qualname__] += 1
        return inner_func(*args)
    return wrap

# a decorator for pre-processing the function and automatically save the result
def pre_process_it (inner_func): 
    import inspect
    import pickle
    a = inspect.getargspec(inner_func)
    if a.args or a.keywords or a.varargs or a.defaults:
        raise ValueError ('A pre process function must not have arguments')        
    
    @time_it
    @wraps(inner_func)
    def wrap (*args):
        filename = 'preprocess_' + inner_func.__qualname__ + '.pickle'
        if not filename in os.listdir():
            print ('--> Pre process started for function \'' + inner_func.__qualname__ + '\' ....')
            preProcessData = inner_func()
            print ('--> Pre process ended for function \'' + inner_func.__qualname__ + '\'')
            print ('--> Pickling started for function \'' + inner_func.__qualname__ + '\' ....')
            with open(filename, 'wb') as f_pp:
                pickle.dump(preProcessData, f_pp, pickle.HIGHEST_PROTOCOL)
            print ('--> Pickling ended for function \'' + inner_func.__qualname__ + '\'')
        print ('--> Unpickling pre-processed data of function \'' + inner_func.__qualname__ + '\' ...')
        with open(filename, 'rb') as f_pp:
            data = pickle.load(f_pp)
        print ('--> Unpickling ended')
        print()
        return data

    return wrap
 

###########################################
# automatic runner
###########################################

# a class to wrap automatically wrap the IO files in one class
class GCJIOWrapper:
    
    def __init__ (self, inputfilename, parsedfilename, outputfilename):
        self.__inputfilename = inputfilename
        self.__parsedfilename = parsedfilename
        self.__outputfilename = outputfilename
        self.__indextestcase = 0
    
    def __enter__ (self):
        # open the IO files
        self.__inputfile = open (self.__inputfilename, 'r')
        self.__parsedfile = open (self.__parsedfilename, 'w')
        self.__outputfile = open (self.__outputfilename, 'w')
    
    def __exit__ (self, typeE, value, tb):
        # close the IO files
        self.__inputfile.close()
        self.__parsedfile.close()
        self.__outputfile.close()
    
    def readline (self):
        # read one line from the input. write it as is to the parsed file
        l = self.__inputfile.readline()
        self.__parsedfile.write(l)
        return l
    
    def newTestcase (self):
        # mark a new testcase to the parsed file
        self.__indextestcase += 1
        self.__parsedfile.write('\n## _BigOnion Testcase: ' + str(self.__indextestcase) + ' ##\n')
    
    def write (self, s):
        # write to the output file
        self.__outputfile.write(s)
    
    def getTestcase (self):
        # return the index of the current testcase
        return self.__indextestcase
        

# This is the automatic runner    
@time_it
def main_run():
        
    # find the most current input file (.in) which is in the working directory 
    print ('Directory : ', os.getcwd())
    filenames = [x for x in os.listdir ()]
    l1 = [(os.stat(x).st_mtime, x) for x in filenames if x.endswith('.in')]
    if not l1:
        raise ValueError('No input file found')
    chosen_prefix =  sorted(l1)[-1][1][:-3]
    input_filename = chosen_prefix+'.in'
    print ('Chosen Input : ',input_filename)
    
    # filename of the file into which to parse the input file
    parsed_filename = chosen_prefix+'.parsed.txt'

    # filename of the output file. It has the same prefix, 
    # and it doesn't tread over the previous output file from previous attempts
    l2 = [x.split('.')[0] for x in filenames if x.endswith('.out') and x.startswith(chosen_prefix)]
    l2 = [int(x.split('-run')[-1]) for x in l2]
    output_file_index = ('000' + str(max([0] + l2) + 1))[-3:]
    output_filename = chosen_prefix + '-run' + output_file_index + '.out'
    print ('Chosen Output : ',output_filename)
    print()
    
    #with open(input_filename) as f_in, open(output_filename, 'w') as f_out:
    #    solve(f_in,f_out)
    ioWrapper = GCJIOWrapper(input_filename, parsed_filename, output_filename)
    with ioWrapper:
        solveAllCases(ioWrapper)

    # print the chosen files once again for easy checking of correctness
    print ()
    print ('Conclusion :')
    print ('Directory : ', os.getcwd())
    print ('Chosen Input : ',input_filename)
    print ('Chosen Output : ',output_filename)


# the automatic solver. Handles the testcase mechanism
@time_it
def solveAllCases (ioWrapper):
    T = int(ioWrapper.readline())
    for testcase in range(1, T+1):
        ioWrapper.newTestcase()
        assert ioWrapper.getTestcase() == testcase
        solveOneCase (ioWrapper)



###########################################
# write code here
###########################################

_mult = {
    ('1','1') : (1,'1'),
    ('1','i') : (1,'i'),
    ('1','j') : (1,'j'),
    ('1','k') : (1,'k'),

    ('i','1') : (1,'i'),
    ('i','i') : (-1,'1'),
    ('i','j') : (1,'k'),
    ('i','k') : (-1,'j'),
    
    ('j','1') : (1,'j'),
    ('j','i') : (-1,'k'),
    ('j','j') : (-1,'1'),
    ('j','k') : (1,'i'),

    ('k','1') : (1,'k'),
    ('k','i') : (1,'j'),
    ('k','j') : (-1,'i'),
    ('k','k') : (-1,'1')
}

@memoize_it
def multiply(a, b):
    sign_a, type_a = a
    sign_b, type_b = b
    sign_res, type_res = _mult[(type_a,type_b)]
    return (sign_a * sign_b * sign_res, type_res)

def solveOneCase__ (ioWrapper):
    # fill details here
    #reset_memoization()
    L, X = [int(x) for x in ioWrapper.readline().split()]
    seq = ioWrapper.readline()
    assert len(seq) == L+1
    seq = seq[:L]
    
    res = 'MAYBE'
    
    cummulative_product_single_seq = (1,'1')
    for c in seq:
        cummulative_product_single_seq = multiply(cummulative_product_single_seq, (1,c))
    cummulative_product_rep = (1,'1')
    for rep in range(X%16):
        cummulative_product_rep = multiply(cummulative_product_rep, cummulative_product_single_seq)
    
    if cummulative_product_rep != (-1,'1'):
        res = 'NO'
    

    if X <= 4:
        XXX = X
    else:
        XXX = (X%4) + 4
    
    if res != 'NO':
        # get first i
        found_i = False
        cummulative_product = (1,'1')
        seq_left = seq * XXX
        for index_left in range(1,len(seq_left)+1):
            letter = seq_left[index_left-1]
            cummulative_product = multiply(cummulative_product, (1,letter))
            if cummulative_product == (1,'i'):
                # found the first index whose product is i
                found_i = True
                break
        
        if not found_i:
            res = 'NO'
            
    if res != 'NO':
        # get last k
        found_k = False
        cummulative_product = (1,'1')
        seq_right = seq * XXX
        for index_right in range(1, len(seq_right)+1):
            letter = seq_right[-index_right]
            cummulative_product = multiply((1,letter), cummulative_product)
            if cummulative_product == (1,'k'):
                # found the last index from which product is k
                found_k = True
                break
        
        if not found_k:
            res = 'NO'
    
    # final check
    if res != 'NO':
        total_index_left = index_left
        assert total_index_left > 0
        assert total_index_left <= X * L
        
        total_index_right = X*L - index_right
        assert total_index_right >= 0
        assert total_index_right < X * L
        
        if index_left + index_right > X * L :
            res = 'NO'
        assert index_left + index_right != X * L
        
        res = 'YES'
    
    
    #output
    assert res in ['YES', 'NO']
    ioWrapper.write('Case #' + str(ioWrapper.getTestcase()) + ': ' + res + '\n')
    



def solveOneCase (ioWrapper):
    # fill details here
    #reset_memoization()
    L, X = [int(x) for x in ioWrapper.readline().split()]
    if X > 16:
        X = (X % 16) + 16
    else:
        pass
    
    seq = ioWrapper.readline()
    assert len(seq) == L+1
    seq = seq[:L] * X
    
    res = 'MAYBE'
    
    cummulative_product_single_seq = (1,'1')
    first_location = len(seq)
    
    for index in range(len(seq)):
        c = seq[index]
        cummulative_product_single_seq = multiply(cummulative_product_single_seq, (1,c))
        if cummulative_product_single_seq == (1,'i'):
            first_location = index
            break
    
    if first_location >= len(seq):
        res = 'NO'
    
    if res != 'NO':
        cummulative_product_single_seq = (1,'1')
        second_location = len(seq)
        for index in range(first_location+1, len(seq)):
            c = seq[index]
            cummulative_product_single_seq = multiply(cummulative_product_single_seq, (1,c))
            if cummulative_product_single_seq == (1,'j'):
                second_location = index
                break
    
        if second_location >= len(seq):
            res = 'NO'

    if res != 'NO':
        cummulative_product_single_seq = (1,'1')
        for index in range(second_location+1, len(seq)):
            c = seq[index]
            cummulative_product_single_seq = multiply(cummulative_product_single_seq, (1,c))
        
        if cummulative_product_single_seq != (1,'k'):
            res = 'NO'
        else:
            res = 'YES'


    #output
    assert res in ['YES', 'NO']
    ioWrapper.write('Case #' + str(ioWrapper.getTestcase()) + ': ' + res + '\n')
    

main_run()
