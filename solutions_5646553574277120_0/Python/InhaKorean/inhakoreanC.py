f_test = ['test.in', 'test.out']
f_small = ['C-small-attempt1.in', 'small.out']
f_large = ['C-large.in', 'large.out']
f_practice_small = ['C-small-practice.in', 'practice_small.out']
f_practice_large = ['C-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

G = []
L = []

def solve(PP, index, t) :
    ret = 100
    if index == len(PP) :
        return t
    for i in PP[index] :
        if i in L : continue
        L.add(i)
        ret = min(ret, solve(PP, index, t+1))
        L.remove(i)
    return ret
def generate(C, D, V, index, val) :
    global G
    if index == D :
        G.append(val)
        return None
    generate(C, D, V, index+1, val + L[index])
    generate(C, D, V, index+1, val)
    return None
def case_result(case) :
    global G, L
    ans = 0
    C, D, V = map(int, f.readline().split())
    L = list(map(int, f.readline().split()))
    G = []
    generate(C, D, V, 0, 0)

    S = set(list(range(V+1))) - set(G)

    L = set(L)
    ans = 0
    PP = []
    for i in range(1, V+1) :
        if i in G : continue
        candi = []
        for j in L :
            if i > j :
                candi.append(i-j)
        PP.append(set(candi))
    ans = solve(PP, 0, 0)
    if ans == 100 : ans = 0
    return str(ans)
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
