from codejam import *

def read_file(f):
    case = read_int_list(f)
    return case

def solver(case):
    k, c, s = case
    check = list(range(0, k, c))
    if s < len(check):
        return 'IMPOSSIBLE'
    for j in range(c-1):
        for n in range(len(check)):
            check[n] = (check[n]+1)%k + k*check[n]
    return ' '.join(map(lambda x: str(x+1), check))

solve('D-large', read_file, solver)
