from math import sqrt

def load_single_case(f):
    return tuple([long(x) for x in f.readline().split()])


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def area(r,N):
    return N*(2*r+2*N-1)

def solve(case):
    r,t=case[0],case[1]
    N=(sqrt((r-.5)**2+2*t)-(r-.5))/2.
    N=long(floor(N))
    # dealing with possible rounding issues
    t0=area(r,N)
    if t0==t:
        return N
    elif t0<t:
        while area(r,N)<t:
            N=N+1
        N=N-1
    else:
        while area(r,N)>t:
            N=N-1
    return N






def outcome_string(outcome):
    return str(outcome)


def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
                f.write("Case #{0}: {1}\n".format( n+1 , outcome_string(o) ))
def process(path_in, path_out=None):
    if path_out==None:
        path_out=path_in.rsplit(".",1)[0]+".out"
    cases=load_cases(path_in)
    outcomes=[solve(c) for c in cases]
    save_outcomes(path_out, outcomes)