# case === (a,b)
def load_single_case(f):
    return [int(n) for n in f.readline().split()]
def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases


def is_palindrome(n):
    s=str(n)
    for i in range(len(s)/2):
        if s[i]!=s[-i-1]:
            return False
    return True
def get_fsqn(case):
    min_sqrt=max(int(sqrt(case[0]))-1,1)
    max_sqrt=int(sqrt(case[1]))+1
    n=0
    for x in range(min_sqrt,max_sqrt+1):
        if is_palindrome(x) and is_palindrome(x**2) and x**2>=case[0] and x**2<=case[1]:
            n=n+1
    return n


def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
            f.write("Case #{0}: {1}\n".format(n+1,o))

def process(path_in, path_out):
    cases=load_cases(path_in)
    outcomes=[get_fsqn(c) for c in cases]
    save_outcomes(path_out, outcomes)