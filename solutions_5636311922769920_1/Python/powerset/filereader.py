with open('/Users/Justin/projects/codejam/D-large.in', 'r+') as f:
    lines = list(f)

T=lines.pop(0).strip()
lines = [ l.strip() for l in lines]

cases=[]
for i in range( int(T) ):
    K, C, S = lines.pop(0).split()
    K, C, S, = int(K), int(C), int(S)

    cases.append({'K': K, 'C': C, 'S': S })

def solve(case):
    K=case['K']
    C=case['C']
    S=case['S']
    answer = ""
    if K > S*C:
        return "IMPOSSIBLE"
    chunksize = K**(C-1)
    marker = 0
    for i in range(1,K+1):

        last = marker + chunksize
        first = marker + 1
        if i == K:
            answer += str(first) + " "
            print "Students used: ", str(len(answer.split()))
            return answer
        if first == last:
            answer += str(first) + " "
            chunksize = K**(C-1)
            marker = chunksize*i
        else:
            chunksize = chunksize/K
            marker += chunksize*i

out = open('/Users/Justin/projects/codejam/output.out', 'w')

j=0
for c in cases:
    j+=1
    st= 'Case #'+str(j)+': '+solve(c)+'\n'
    print st
    out.write(st)

