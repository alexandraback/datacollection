with open('/Users/Justin/projects/codejam/A-large.in', 'r+') as f:
    lines = list(f)

T=lines.pop(0).strip()
lines = [ l.strip().split() for l in lines]

cases=[]
for i in range( int(T) ):
    N = lines.pop(0)
    N=int(N[0])

    cases.append({'N': N })

def solve(case):
    N=case['N']
    if N==0:
        return "INSOMNIA"
    i=0
    s = set()
    while True:
        s=s.union( set(str( N + (N * i ) )) )
        if len(s)==10:
            return str(N + (N * i) )
        else:
            i+=1

out = open('/Users/Justin/projects/codejam/output.out', 'w')

j=0
for c in cases:
    j+=1
    st= 'Case #'+str(j)+': '+solve(c)+'\n'
    print st
    out.write(st)

