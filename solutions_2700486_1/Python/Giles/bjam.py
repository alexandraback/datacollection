from codejam.utils.codejamrunner import CodeJamRunner
import codejam.utils.graphing as graphing
import networkx as nx
import math

from decimal import *
getcontext().prec = 300

class Dynam(object):pass

def generate_triangular_numbers(limit):

    last_num = 1
    triangular_numbers = [1]
    i = 2
    while triangular_numbers[-1] < limit:
        last_num += i
        if i %2 :
            triangular_numbers.append(last_num)
        i+=1

    return triangular_numbers

def is_central_square(x,y):
    return not (x+y) % 2

def find_row(x,y):
    row = abs(x) / 2.0
    r_offset= y /2.0
    return int(row + r_offset)
    
def find_row_size(row):
    return (row* 4) +1

def for_k(n,k):

    top =  Decimal(math.factorial(n))
    bot = Decimal(math.factorial(k) * Decimal(math.factorial(n-k)))
    return (top * Decimal(0.5)**n)/ bot

def find_partial_row_prob(n, k):
    p = 0
    
    while k<=n:
        p += for_k(n,k)
        k+=1
    
    return p

def solver(data):

    #import pdb;pdb.set_trace()
    if not is_central_square(data.x, data.y):
        return 0.0

    row = find_row(data.x, data.y)
    row_size = find_row_size(row)

    if row > len(tris):
        return 0.0
    
    if data.n >= tris[row]:
        return 1.0

    if data.n <= tris[row-1]:
        return 0.0

    if data.x == 0:
        #row must be full if we are using this one.
        return 0.0

    # need to check this what if row count is above half
    row_remaining  = data.n - tris[row-1]    
    f = data.y+1
    
    if f > row_remaining:
        return 0.0
    if f + (row_size / 2) <= row_remaining:
        return 1.0

    part_prob = find_partial_row_prob(row_remaining, f)
    return '%0.8f' % part_prob


  
def data_builder(f):

    data = Dynam()
    data.n, data.x, data.y = f.get_ints()

    return data

tris = generate_triangular_numbers(10**8)

def test():
    assert is_central_square(0,0)
    assert is_central_square(2,0)
    assert is_central_square(-2,0)
    assert is_central_square(2,4)
    assert is_central_square(-2,4)
    assert is_central_square(1,1)
    assert is_central_square(-1,1)
    assert is_central_square(-1,3)
    assert is_central_square(-3,1)
    assert not is_central_square(0,1)
    assert not is_central_square(2,1)
    assert not is_central_square(-2,1)
    assert not is_central_square(-1,2)



    assert find_row(0,0) == 0
    assert find_row(-2,0) == 1
    assert find_row(2,0) == 1
    assert find_row(1,1) == 1
    assert find_row(0,2) == 1
    assert find_row(3,1) == 2
    assert find_row(-4,0) == 2
    assert find_row(4,0) == 2
    assert find_row(0, 4) == 2
    assert find_row(2,2) == 2

    print find_partial_row_prob(2,1)
    assert find_partial_row_prob(2,1) == 0.75
    assert find_partial_row_prob(2,2) == 0.25
    #assert find_partial_row_prob(2,1) == 0.75
    #assert find_partial_row_prob(2,1) == 0.75
    print 'quick tests passed'

    
#test()


cjr = CodeJamRunner()
cjr.run(data_builder, solver, problem_name = "B", problem_size='large')
