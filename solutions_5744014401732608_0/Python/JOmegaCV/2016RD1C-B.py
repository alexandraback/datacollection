'''
Created on May 7, 2016

@author: John Cornwell
'''
import operator,math,string,itertools,fractions,requests,os
import heapq,collections,re,array,bisect,random,time,inspect
import multiprocessing as mp
# pip install hopcroftkarp
from hopcroftkarp import HopcroftKarp
import numpy as np
import multiprocessing.pool as mpp
from fractions import gcd
import datetime as dt

def lcm(a, b):
    return a * b / gcd(a, b)

def lambda_post(func, args):
    url = 'https://td1vnd4ygb.execute-api.us-east-1.amazonaws.com/prod/python_exec'
    api_key = 'ZSNsVcEvls7UZSjt7SHGK2ofMkY88Qy83EuLTdnz'
    retries = 7
    delay = 0.1
    while retries != 0:
        function = ''.join(inspect.getsourcelines(func)[0])
        data = {'code': function,
                'name': func.__name__,
                'args': args}
        headers = {'x-api-key': api_key}
        response = requests.post(url, json=data, headers=headers, timeout=300)
        # URL runs the following code:
        # def lambda_handler(event, context):
        #     code = event['code']
        #     name = event['name']
        #     args = event['args']
        #
        #     exec(code)
        #     func = locals()[name]
        #     return func(*args)
        if response.status_code == 200:
            break
        print 'Warning, rety on', response.status_code, response.json()
        retries -= 1
        time.sleep(delay)
        delay *= 2

    return response.json()



# Called before solving any functions
def init(i_num, fc_in):
    return

# Parse next set of arguments
def parse_next(fc_in):
    B, M = map(int, fc_in.readline().split())
    return (B, M)


# Solve individual instance
def solve(B, M):
    mx = 2 ** (B-2)
    
    
    if M > mx:
        return 'IMPOSSIBLE'
    
    slides = [[0] * B for x in range(B)]
    for i in range(B):
        for j in range(i+1, B):
            slides[i][j] = 1
    
    if mx != M:
        slides[0][B-1] = 0
        brep = bin(M)[2:]
        brep = ('0' * (B - len(brep) - 2)) + brep
        
        for i, bit in enumerate(brep):
            if bit == '0':
                slides[0][i+1] = 0
        
    ret = 'POSSIBLE\n'
    slide_str = []
    for line in slides:
        slide_str.append(''.join(map(str, line)))
    ret += '\n'.join(slide_str)
    
    return ret

    
    

def _run_main():
    # Config
    s_let = os.path.splitext(__file__)[0][-1]
    s_run = 1
    distrib = 0 # 0-single, 1-parallel, 2-lambda

    if s_run == 0:
        fc_in = open('infile.in', 'r')
    elif s_run == 1:
        fc_in = open('Z:\Users\John Cornwell\Desktop\%s-small-attempt1.in' % s_let, 'r')
    elif s_run == 2:
        fc_in = open('Z:\Users\John Cornwell\Desktop\%s-large.in' % s_let, 'r')
    elif s_run == 3:
        fc_in = open('Z:\Users\John Cornwell\Desktop\%s-small-practice.in' % s_let, 'r')
    elif s_run == 4:
        fc_in = open('Z:\Users\John Cornwell\Desktop\%s-large-practice.in' % s_let, 'r')
    fc_out = open('out.txt', 'w')

    i_num = int(fc_in.readline())
    init(i_num, fc_in)

    dt_start = dt.datetime.now()
    # Parse and solve test cases
    if distrib == 0:
        for i in range(1, i_num+1):
            args = parse_next(fc_in)
            ret = solve(*args)
            s_line = 'Case #%i: %s' % (i, str(ret))
            print s_line
            fc_out.write(s_line + '\n')
    # Run jobs in parallel
    elif distrib == 1:
        new_pool = mp.Pool()
        results = []
        for i in range(1, i_num+1):
            args = parse_next(fc_in)
            results.append(new_pool.apply_async(solve, args))
        for i, r in enumerate(results):
            ret = r.get()
            s_line = 'Case #%i: %s' % (i + 1, str(ret))
            print s_line
            fc_out.write(s_line + '\n')
    # Run jobs in parallel in the cloud
    elif distrib == 2:
        new_pool = mpp.ThreadPool(900)
        results = []
        for i in range(1, i_num+1):
            args = parse_next(fc_in)
            results.append(new_pool.apply_async(lambda_post,
                                                kwds={'func': solve,
                                                      'args': args}))
        for i, r in enumerate(results):
            ret = r.get()
            s_line = 'Case #%i: %s' % (i + 1, str(ret))
            print s_line
            fc_out.write(s_line + '\n')
    print dt.datetime.now() - dt_start, 'total runtime'


if __name__ == '__main__':
    _run_main()