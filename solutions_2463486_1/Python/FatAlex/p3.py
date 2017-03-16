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


def build_palindrome(n,m=None):
    if m==None:
        return int(str(n)+str(n)[::-1])
    else:
        return int(str(n)+str(m)+str(n)[::-1])
def build_palindrome_list(l):
    if l==1:
        return range(1,10)
    lst=[]
    if l%2==0:
        for i in xrange(10**(l/2-1),10**(l/2)):
            lst.append(build_palindrome(i))
    else:
        for i in xrange(10**(l/2-1),10**(l/2)):
            for j in range(10):
                lst.append(build_palindrome(i,j))
    return lst
def build_complete_palindrome_list(l):
    lst=[]
    for i in range(1,l+1):
        lst=lst+build_palindrome_list(i)
    return lst

def is_palindrome(n):
    s=str(n)
    for i in range(len(s)/2):
        if s[i]!=s[-i-1]:
            return False
    return True
def refine_pali_list(lst):
    ref_lst=[]
    for x in lst:
        if is_palindrome(x**2):
            ref_lst.append(x)
    return ref_lst
pali_list=refine_pali_list(build_complete_palindrome_list(7))

def get_fsqn(case):
    min_sqrt=max(int(sqrt(case[0]))-1,1)
    max_sqrt=int(sqrt(case[1]))+1
    n=0
    for x in pali_list:
        if x**2>=case[0] and x**2<=case[1]:
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