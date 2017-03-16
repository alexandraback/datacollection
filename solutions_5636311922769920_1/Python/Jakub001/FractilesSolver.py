from DomainModel.TestCase import TestCase

def process(a,x):
    n = ''
    for c in a:
        if c=='G':
            n += 'G'*len(x)
        else:
            n += x
    return n

class FractilesSolver:
    def Solve(self):
        tests = int(input())
        for test in range(tests):
            K,C,S = [int(x) for x in input().split()]
            if C==1:
                opt = list(x for x in range(1,K+1))
            elif C>=K:
                opt = [(K**K)//((K-1)**2)]
            else:
                opt = list(x for x in range(2,3+K-C))

            if len(opt)>S:
                ret = 'IMPOSSIBLE'
            else:
                ret = ' '.join([str(x) for x in opt])
            print("Case #{}: {}".format(test+1,ret))

    def Solve2(self):
        n=6
        c=n
        a=[]
        for i in range(n):
            p = 'L'*i + 'G' + 'L'*(n-i-1)
            np = p
            for k in range(c-1):
                np = process(np,p)
            print(p+" : "+np)
            a.append(np)
        b=[]
        cnt=0
        pos=None
        for x in zip(*a):
            cnt+=1
            val = sum(1 for l in x if l=='G')
            b.append(str(val))
            if(val==n and not pos):
                pos=cnt
        print (' '*n + '   ' + ''.join(b))
        print ("{}/{}".format(pos,n**c))





    def Tests(self):
        yield TestCase("""5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
""","""Case #1: 2
Case #2: 1
Case #3: IMPOSSIBLE
Case #4: 1 2
Case #5: 2 6
""")