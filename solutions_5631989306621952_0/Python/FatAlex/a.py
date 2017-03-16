import sys
sys.setrecursionlimit(10000)

def read_line(f):
    while True:
        s=f.readline().strip()
        if s:
            return s
def read_list(f):
    return [int(x) for x in read_line(f).split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    return read_line(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def gen_word(s, path):
    fmt="{:0"+str(len(s))+"b}"
    path=fmt.format(path)
    r=""
    for c,p in zip(s,path):
        if p=="0":
            r=r+c
        else:
            r=c+r
    return r
def solve_bf(case):
    s=case
    mw=s
    for p in xrange(2**len(s)):
        w=gen_word(s,p)
        if w>mw:
            mw=w
    return mw
    

def max_right(s):
    mp=0
    for i in xrange(len(s)):
        if s[i]>=s[mp]:
            mp=i
    return mp

def maximize(s):
    if len(s)<2:
        return s
    mp=max_right(s)
    return s[mp]+maximize(s[:mp])+s[mp+1:]

def solve(case):
    s=case
    return maximize(s)






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
    





########## SOLUTIONS TESTING ##########


def verify_outcome(case, outcome):
    return outcome==solve_bf(case)

def test_solutions(path_in, until_first_fail=True):
    cases=load_cases(path_in)
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"

def gen_cases():
    ### IMPLEMENT ###
    return []

def test_solutions_gen(until_first_fail=True):
    cases=gen_cases()
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"