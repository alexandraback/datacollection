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
    read_line(f)
    return read_list(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def build_conn(bffs):
    conn={}
    for i,b in bffs:
        conn.setdefault(i,[]).append(b)
        conn.setdefault(b,[]).append(i)
    return conn

'''def find_cycle(bffs,s):
    c={s}
    x=s
    while bffs[x]!=s:
        x=bffs[x]
        if x in c:
            return None
        c.add(x)
    return c
def search_cycles(bffs):
    cycles={}
    included=set()
    for s in xrange(len(bffs)):
        if s in included:
            pass
        c=find_cycle(bffs,s)
        if c is not None:
            included=included|c
            cycles.setdefault(len(c),set()).add(min(c))
    return cycles'''


'''def find_cycle(bffs, s, ts):
    c={s}
    cl=[s]
    x=s
    while bffs[x]!=s:
        x=bffs[x]
        if x in c:
            return None
        c.add(x)
        cl.append(x)
    return c'''

'''def search(i, bffs, ts, cyc):
    if i in ts:
        return ts[i]
    bres=search()'''

def search(s, bffs, ts):
    path=[]
    visited=set()
    x=s
    while True:
        if x in ts:
            if ts[x][0]=="tp":
                #print "tp", x, path
                tpi,tpl=ts[x][1:]
                for y in path[::-1]:
                    tpl=tpl+1
                    ts[y]=("tp",tpi,tpl)
            else:
                for y in path[::-1]:
                    ts[y]=("dead",)
            return
        if x in visited:
            #print "cyc", x, path
            cl=None
            for i,y in enumerate(path):
                if y==x:
                    cl=len(path)-i
                if cl is None:
                    ts[y]=("dead",)
                else:
                    ts[y]=("cyc",cl)
            return
        path.append(x)
        visited.add(x)
        x=bffs[x]
            
def classify(bffs):
    ts={}
    l=len(bffs)
    for i in xrange(l):
        if bffs[bffs[i]]==i:
            ts[i]=("tp",i,1)
    for i in xrange(l):
        if i not in ts:
            search(i,bffs,ts)
    #print ts
    tp_lens={}
    max_cyc=0
    for t in ts.itervalues():
        if t[0]=="cyc":
            max_cyc=max(max_cyc,t[1])
        elif t[0]=="tp":
            tpi,tpl=t[1:]
            tp_lens[tpi]=max(tp_lens.get(tpi,0),tpl)
    tp_len=sum(tp_lens.values())
    return max(tp_len,max_cyc)
    
    


def solve(case):
    bffs=[x-1 for x in case]
    '''print bffs
    cycles=search_cycles(bffs)
    max_c=max(cycles.keys())
    max_p=len(cycles.setdefault(2,[]))*2
    print cycles, max_c, max_p
    return max(max_c,max_p)'''
    return classify(bffs)






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