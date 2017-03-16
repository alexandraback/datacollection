def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    l,x=read_tuple(f)
    s=f.readline().strip()
    assert (len(s)==l)
    return x,s


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def neg(c):
    return "-"+c[1] if (c[0]=="+") else "+"+c[1]
_mult_elem={"11":"+1","1i":"+i","1j":"+j","1k":"+k",
            "i1":"+i","ii":"-1","ij":"+k","ik":"-j",
            "j1":"+j","ji":"-k","jj":"-1","jk":"+i",
            "k1":"+k","ki":"+j","kj":"-i","kk":"-1"}
def mul(c1,c2):
    ns=(c1[0]=="-")+(c2[0]=="-")
    pprod=_mult_elem[c1[1]+c2[1]]
    if ns==1:
        return neg(pprod)
    return pprod
def pow(c,n):
    if c=="+1":
        return "+1"
    if c=="-1":
        return "+1" if (n%2==0) else "-1"
    if n%4==0:
        return "+1"
    if n%4==1:
        return c
    if n%4==2:
        return "-1"
    return neg(c)


def find_start(s,x):
    n="+1"
    for i,c in enumerate(s):
        if n==x:
            return i
        n=mul(n,c)
    return -1
def find_end(s,x):
    n="+1"
    for i,c in enumerate(s[::-1]):
        if n==x:
            return i
        n=mul(c,n)
    return -1


def s2l(s):
    return ["+"+c for c in s]


def solve(case):
    x,s=case
    s=s2l(s)
    if pow(reduce(mul,s),x)!="-1":
        return False
    start=find_start(s*4,"+i")
    end=find_end(s*4,"+k")
    if start<0 or end<0 or (start+end>x*len(s)):
        return False
    return True






def outcome_string(outcome):
    return "YES" if outcome else "NO"


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