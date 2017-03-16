# case = ((E,R),list[vi])
def load_single_case(f):
    l=[int(x) for x in f.readline().split()]
    E,R=l[0],l[1]
    v=[int(x) for x in f.readline().split()]
    return ((E,R),v)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def call(n):
    if n==0:
        return None
    else:
        return call(n-1)

def solve(case):
    E,R,v=case[0][0],case[0][1],case[1]
    if R>=E:
        return sum(v)*E
    N=len(v)
    t=[[0]*(E+1) for _ in xrange(N+1)] #t[n][e] - max gain from making first n+1 tasks while leaving r energy (after regaining energy)
    for n in xrange(1,N+1):
        for e in xrange(0,E):
            l=[t[n-1][e+s]+v[n-1]*s for s in xrange(0,E-e+1)]
            el=min(e+R,E)
            t[n][el]=max(max(l),t[n][el])
    return max(t[N])






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