def read_list(f):
    return [int(x) for x in f.readline().split()]
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




def gen_free_square(R,C,fR,fC): # R,C>=3; fR,fC>=3
    mR=R-fR
    mC=C-fC
    t=["c"+"."*(fC-1)+"*"*mC]
    for _ in xrange(1,fR):
        t.append("."*fC+"*"*mC)
    for _ in xrange(fR,R):
        t.append("*"*C)
    return t
def fill_column(t, C, Ri, Rf):
    new_t=t
    for r in xrange(Ri,Rf):
        new_t[r]=new_t[r][:C]+"*"+new_t[r][C+1:]
    return new_t
def gen_table(R, C, M): #assume R<=C
    F=R*C-M
    if R==1:
        return ["c"+"."*(F-1)+"*"*M]
    elif R==2:
        if F==1:
            return gen_free_square(R,C,1,1)
        elif F%2==0 and F>2:
            return ["c"+"."*(F/2-1)+"*"*(M/2), "."*(F/2)+"*"*(M/2)]
        else:
            return None
    else:
        if F<=9:
            if F in [2,3,5,7]:
                return None
            if F==1:
                return gen_free_square(R,C,1,1)
            elif F==4:
                return gen_free_square(R,C,2,2)
            elif F==6:
                return gen_free_square(R,C,2,3)
            elif F==8:
                t=gen_free_square(R,C,3,3)
                return fill_column(t,2,2,3)
            elif F==9:
                return gen_free_square(R,C,3,3)
        else:
            if F>R*3:
                fC=(F-1)/R+1
                mR=M%R
                t=gen_free_square(R,C,R,fC)
                if (mR==R-1):
                    t=fill_column(t,fC-1,2,R)
                    return fill_column(t,fC-2,R-1,R)
                else:
                    return fill_column(t,fC-1,0,mR)
            else:
                fC=(F-1)/3+1
                t=gen_free_square(R,C,fC,3)
                if F%3==0:
                    return t
                elif F%3==2:
                    return fill_column(t,2,fC-1,fC)
                else:
                    return fill_column(t,2,fC-2,fC)
def transpose(t):
    return t and ["".join(l) for l in zip(*t)]
def solve(case):
    R,C,M=case
    if R<=C:
        return gen_table(R,C,M)
    else:
        return transpose(gen_table(C,R,M))





def outcome_string(outcome):
    if outcome:
        return "\n"+"\n".join(outcome)
    else:
        return "\nImpossible"

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