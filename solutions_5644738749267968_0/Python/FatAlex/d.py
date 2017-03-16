def read_list(f):
    return [float(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    _=read_tuple(f)
    N=read_list(f)
    K=read_list(f)
    return (N,K)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def war_win(N, K):
    N=[i for i in N]
    N.sort()
    K=[i for i in K]
    K.sort()
    w=0
    n=len(N)
    for _ in xrange(n):
        if N[-1]>K[-1]:
            w=w+1
            K=K[1:]
        else:
            K=K[:-1]
        N=N[:-1]
    return w

def dwar_win(N, K):
    N=[i for i in N]
    N.sort()
    K=[i for i in K]
    K.sort()
    w=0
    n=len(N)
    for _ in xrange(n):
        if N[0]>K[0]:
            w=w+1
            K=K[1:]
        else:
            K=K[:-1]
        N=N[1:]
    return w

def solve(case):
    N,K=case
    return dwar_win(N,K), war_win(N,K)






def outcome_string(outcome):
    return "{0} {1}".format(*outcome)


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