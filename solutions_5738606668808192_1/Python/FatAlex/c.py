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




maxBCL=32
def gen_primes(N):
    primes=[]
    for i in xrange(2,N+1):
        is_prime=True
        for p in primes:
            if i%p==0:
                is_prime=False
                break
        if is_prime:
            primes.append(i)
    return primes
primes=gen_primes(2**(maxBCL//2+1))

def check_prime(x):
    for p in primes:
        if p**2>x:
            return 0
        if x%p==0:
            return p
    return 0

def check_coin(c):
    divs=[]
    for b in xrange(2,11):
        n=int(c,b)
        d=check_prime(n)
        if d:
            divs.append(d)
        else:
            return []
    return divs
 
 
def mine(N, l):
    coins=[]
    x=int("1"+"0"*(l-2)+"1",2)
    while len(coins)<N:
        c="{:b}".format(x)
        divs=check_coin(c)
        if divs:
            coins.append((c,divs))
        x=x+2
    return coins

def solve(case):
    l,N=case
    return mine(N,l)






def outcome_string(outcome):
    return "".join([ "\n{} {}".format(o[0]," ".join([str(d) for d in o[1]])) for o in outcome ])


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