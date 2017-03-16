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
    N,=read_tuple(f)
    return [read_list(f) for _ in xrange(2*N-1)]


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def find_min_pos(lines, p):
    min_v=min([l[p] for l in lines])
    ps=[i for i in xrange(len(lines)) if lines[i][p]==min_v]
    return ps
def find_max_pos(lines, p):
    max_v=max([l[p] for l in lines])
    ps=[i for i in xrange(len(lines)) if lines[i][p]==max_v]
    return ps
def find_missing_min(lines):
    lines=list(lines)
    for p in xrange(len(lines)//2+1):
        ps=find_min_pos(lines,p)
        assert len(ps) in {1,2}
        if len(ps)==1:
            return p,lines[ps[0]]
        elif len(ps)==2:
            assert ps[1]>ps[0]
            del lines[ps[1]]
            del lines[ps[0]]
def find_missing_max(lines):
    lines=list(lines)
    for p in xrange(len(lines)//2,-1,-1):
        ps=find_max_pos(lines,p)
        assert len(ps) in {1,2}
        if len(ps)==1:
            return p,lines[ps[0]]
        elif len(ps)==2:
            assert ps[1]>ps[0]
            del lines[ps[1]]
            del lines[ps[0]]


def solve(case):
    lines=case
    mmin,mminc=find_missing_min(lines)
    mmax,mmaxc=find_missing_max(lines)
    assert mmin==mmax
    assert mminc==mmaxc
    nums=[l[mmin] for l in lines]
    for x in mminc:
        del nums[nums.index(x)]
    nums=nums+[mminc[mmin]]
    nums.sort()
    return nums






def outcome_string(outcome):
    return " ".join([str(c) for c in outcome])


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
    ### IMPLEMENT ###
    return outcome==solve(case)

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