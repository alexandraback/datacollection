def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    return read_tuple(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def count_simple(A,B,K):
    n=0
    for a in xrange(A):
        for b in xrange(B):
            if a&b<K:
                n=n+1
    return n
def solve(case):
    A,B,K=case
    return count_simple(A,B,K)






def outcome_string(outcome):
    return "{}".format(outcome)


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