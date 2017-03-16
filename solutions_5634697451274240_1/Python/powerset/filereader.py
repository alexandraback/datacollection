with open('/Users/Justin/projects/codejam/B-large.in', 'r+') as f:
    lines = list(f)

T=lines.pop(0).strip()
lines = [ l.strip() for l in lines]

cases=[]
for i in range( int(T) ):
    S = lines.pop(0)

    cases.append({'S': S })

swap = {"+": "-", "-": "+"}
def flip(s, i):
    top = s[:i]
    toplist = [ j for j in top]
    toplist.reverse()
    new = [ swap[j] for j in toplist ]
    first = "".join(new)
    return first + s[i:]

def solve(case):
    S=case['S']
    answer = 0
    while "-" in S:
        if S[0] == "-":
            i = S.rindex("-") +1
            S = flip(S, i)
            answer +=1
        else:
            i = S.index("-")
            S = flip(S, i)
            answer += 1
    return str(answer)

out = open('/Users/Justin/projects/codejam/output.out', 'w')

j=0
for c in cases:
    j+=1
    st= 'Case #'+str(j)+': '+solve(c)+'\n'
    print st
    out.write(st)

