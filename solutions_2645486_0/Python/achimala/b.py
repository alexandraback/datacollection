mem = {}
def f(E, maxE, R, v):
    tv = tuple(v)
    try:
        return mem[E,maxE,R,tv]
    except:
        if len(v) == 0:
            return 0
        answers = set()
        for S in range(E+1):
            newE = min(E - S + R, maxE)
            answers.add(S*v[0] + f(newE, maxE, R, v[1:]))
        mem[E,maxE,R,tv] = max(answers)
        return mem[E,maxE,R,tv]

T = int(raw_input())
for case in range(1,T+1):
    E,R,N = map(int, raw_input().split())
    v = map(int, raw_input().split())
    print "Case #{}: {}".format(case, f(E,E,R,v))