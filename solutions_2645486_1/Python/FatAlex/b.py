import sys
sys.setrecursionlimit(10000)

# case = ((E,R),list[vi])
def load_single_case(f):
    l=[long(x) for x in f.readline().split()]
    E,R=l[0],l[1]
    v=[long(x) for x in f.readline().split()]
    return ((E,R),v)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases





def gain(e0,v,max_end,case):
    if v==[]:
        return (0,e0)
    E,R=case[0][0],case[0][1]
    if len(v)==1:
        if max_end:
            if e0+R<=E:
                return (0,e0+R)
            else:
                return ((e0+R-E)*v[0],E)
        else:
            return (v[0]*e0,R)
    max_n=v.index(max(v))
    fp=gain(e0,v[:max_n],True,case)
    sp=gain(R,v[max_n+1:],max_end,case)
    if max_end:
        if sp[1]==E:
            return (fp[0]+sp[0]+v[max_n]*fp[1],sp[1])
        else:
            if fp[1]+sp[1]<=E:
                return (fp[0]+sp[0],fp[1]+sp[1])
            else:
                return (fp[0]+sp[0]+v[max_n]*(fp[1]+sp[1]-E),E)
    else:
        return (fp[0]+sp[0]+v[max_n]*fp[1],sp[1])
            


def solve(case):
    return gain(case[0][0],case[1],False,case)[0]






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