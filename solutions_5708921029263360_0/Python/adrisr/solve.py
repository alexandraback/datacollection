
class Solver:
    def __init__(self,J,P,S,K):
        self.used = {}
        self.usedJP = {}
        self.usedPS = {}
        self.usedSJ = {}
        self.J = J
        self.P = P
        self.S = S
        self.K = K

    def solve_day(self):
        for j in range(1,1+self.J):
            for p in range(1,1+self.P):
                for s in range(1,1+self.S):
                    outfit = (j,p,s)
                    if not outfit in self.used:
                        jp = (j,p)
                        ps = (p,s)
                        sj = (s,j)
                        v_jp = 0 if not jp in self.usedJP else self.usedJP[jp]
                        v_ps = 0 if not ps in self.usedPS else self.usedPS[ps]
                        v_sj = 0 if not sj in self.usedSJ else self.usedSJ[sj]

                        if v_jp<self.K and v_ps<self.K and v_sj<self.K:
                             self.used[outfit] = True
                             self.usedJP[jp] = v_jp + 1
                             self.usedPS[ps] = v_ps + 1
                             self.usedSJ[sj] = v_sj + 1
                             return outfit
        return [False]

    def solve(self):
        result = []
        while True:
           r = self.solve_day()
           if len(r)==3:
               result.append(r)
           else:
               break
        return result

NUM_CASES = int(input())
for case_num in range(NUM_CASES):
    p= list(map(int,input().split()))
    s = Solver(p[0],p[1],p[2],p[3])
    result = s.solve()
    print('Case #{0:d}: {1:d}'.format(case_num+1,len(result)))
    for line in result:
        print(' '.join(map(str,line)))

