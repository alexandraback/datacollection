f = open('A-large.in', 'r')
fo = open('A-large.out', 'w')
T = int(f.readline())
for caseID in range(1, T+1):
    S = f.readline()
    r = ''
    for c in S.strip():
        if r == '' or c >= r[0]:
            r = c + r
        else:
            r = r + c
    fo.write('Case #{}: {}\n'.format(caseID, r))
    
        