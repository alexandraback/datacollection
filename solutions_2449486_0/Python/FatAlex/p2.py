# case === list(list(int)[0:N])[0:M]
def load_single_case(f):
    sizes=[int(n) for n in f.readline().split()]
    lawn=[]
    for _ in xrange(sizes[0]):
        lawn.append([int(n) for n in f.readline().split()])
    return lawn 
def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases


def check_case(case):
    N,M=len(case),len(case[0])
    row_max=[max(r) for r in case]
    col_max=[max([case[r][c] for r in range(N)]) for c in range(M)]
    for r in xrange(N):
        for c in xrange(M):
            if case[r][c]<min(row_max[r],col_max[c]):
                return False
    return True


statuses={False:'NO',True:'YES'}
def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
            f.write("Case #{0}: {1}\n".format(n+1,statuses[o]))

def process(path_in, path_out):
    cases=load_cases(path_in)
    outcomes=[check_case(c) for c in cases]
    save_outcomes(path_out, outcomes)