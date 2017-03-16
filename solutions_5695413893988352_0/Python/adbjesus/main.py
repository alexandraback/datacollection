def solve():
    S = [s for s in input().split()]

    C1 = [S[0]]
    for i in range(S[0].count('?')):
        tmp = []
        for w in C1:
            i = w.find('?')
            for j in range(10):
                tmp.append(w[:i]+str(j)+w[i+1:])
        C1 = tmp[::]
    
    C2 = [S[1]]
    for i in range(S[1].count('?')):
        tmp = []
        for w in C2:
            i = w.find('?')
            for j in range(10):
                tmp.append(w[:i]+str(j)+w[i+1:])
        C2 = tmp[::]

    md = 1000000000000000000
    s1 = 1000000000000000000
    s2 = 1000000000000000000
    for i in C1:
        for j in C2:
            dif = abs(int(i) - (int(j)))
            if(dif < md):
                md = dif
                s1 = int(i)
                s2 = int(j)
            elif(dif == md and int(i)<s1):
                s1 = int(i)
                s2 = int(j)
            elif(dif == md and int(i)==s1 and int(j)<s2):
                s2 = int(j)
     
    return "%s %s" % (str(s1).zfill(len(S[0])), str(s2).zfill(len(S[0])))

T = int(input())
for t in range(1,T+1):
    print("Case #%d: %s" % (t,solve()))
