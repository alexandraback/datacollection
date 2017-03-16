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

@memoize_it
def count (n):
    assert n >= 0
    if n == 1:
        return 1
    else:
        if n % 10 == 0:
            return count(n-1) + 1        
        else:
            a = count(n-1)
            rev_n = int(''.join(str(n)[::-1]))
            b = count(rev_n)
            return min(a,b) + 1


def count2 (n):
    start = int('1' + '0' * (len(str(n))-1))
    if start == n and start not in d:
        res = count2(n-1) + 1
        d[n] = res
        return res
    print (n)
    assert start in d
    s = [n]
    used = set()
    cnt = d[start]
    while start not in s:
        s2 = []
        used = used.union(s)
        for i in s:
            if i-1 not in used:
                s2.append(i-1)
            if i % 10 != 0:
                rev_i = int(''.join(str(i)[::-1]))
                if rev_i not in used and rev_i < i:
                    s2.append(rev_i)
        s = list(set(s2))
        cnt += 1
    
    return cnt
    
def reverse(n):
    return int(str(n)[::-1])

@memoize_it
def count3 (n):
    if n < 20:
        return n
    start = int('1' + '0' * (len(str(n))-1))
    if n%10 == 0:
        res = count3(n-1) + 1
        return res
    simple = n - start
    l = len(str(n))
    first_half = int(str(n)[:l//2][::-1])
    second_half = int(str(n)[l//2:])
    return count3(start) + min(simple, first_half + second_half)
    


def solveOneCase (ioWrapper):
    # fill details here
    #reset_memoization()
    n = int(ioWrapper.readline())
    print (ioWrapper.getTestcase(), n)
    ioWrapper.write('Case #' + str(ioWrapper.getTestcase()) + ': ' + str(count3(n)) + '\n')





main_run()
