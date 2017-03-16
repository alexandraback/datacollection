f = open('B-large.in', 'r')
fo = open('B-large.out', 'w')
T = int(f.readline())
for caseID in range(1, T+1):
    N = int(f.readline())
    d = {}
    for i in range(2*N-1):
        s = f.readline().strip().split()
        for c in s:
            if c not in d:
                d[c] = 0
            d[c] += 1
    l = []
    for k in d:
        if d[k]%2 == 1:
            l.append(int(k))
    r = ''
    for c in sorted(l):
        r = r +' '+str(c)
    fo.write('Case #{}:{}\n'.format(caseID, r))
    
            
        