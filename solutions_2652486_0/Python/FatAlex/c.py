# case = ((N,M), list[list[n]*K]*R)
def load_single_case(f):
    R,N,M,K=tuple([int(x) for x in f.readline().split()])
    cases=[]
    for _ in xrange(R):
        cases.append([int(x) for x in f.readline().split()])
    return ((N,M),cases)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def gen_cases_r(N,fa):
    if N==0:
        return [[]]
    scs=gen_cases_r(N-1,fa)
    cs=[]
    for sc in scs:
        for f in fa:
            cs.append(sc+[f])
    return cs
def gen_cases(N,M):
    return gen_cases_r(N,range(2,M+1))


def products_r(c):
    if c==[]:
        return [1]
    sps=products_r(c[1:])
    return sps+[c[0]*sp for sp in sps]
def products(c): # all possible subset products
    ps=products_r(c)
    ups=[]
    for p in ps:
        if not (p in ups):
            ups.append(p)
    return ups

def solve(case):
    N,M=case[0][0],case[0][1]
    cs=gen_cases(N,M)
    ps=[products(c) for c in cs]
    outcome=[]
    for ss in case[1]:
        fitting=range(len(cs))
        for s in ss:
            new_fitting=[]
            for f in fitting:
                if s in ps[f]:
                    new_fitting.append(f)
            fitting=new_fitting
        outcome.append(cs[fitting[0]])
    return outcome






def outcome_string(outcome):
    return "\n"+"\n".join(["".join([str(x) for x in o]) for o in outcome])


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