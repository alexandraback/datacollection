import sys

f = open('C-large.in')
f_out = open('C-large.out', 'w')

T = int(f.readline())
for k in range(T):
    line = f.readline().split()
    C = int(line[0])
    D = int(line[1])
    V = int(line[2])
    line = f.readline().split()
    temp = [int(x) for x in line]
    if temp[0] != 1:
        den = [1]
        den.extend(temp)
        ans = 1
    else:
        den = temp
        ans = 0
    if len(den)==1:
        ctt = 1
        while ctt*C<V:
            ans += 1
            newv = ctt*C+1
            ctt += newv
    else:
        ctt = 0
        for ind in range(len(den)-1):
            ctv = den[ind]
            ntv = den[ind+1]
            ctt += ctv
            if ctt*C >= V:
                break
            while ctt*C<ntv-1:
                ans += 1
                newv = ctt*C+1
                ctt += newv
                if ctt*C >= V:
                    break
        ctt += ntv
        while ctt*C<V:
            ans += 1
            newv = ctt*C+1
            ctt += newv
    f_out.write('Case #{0}: {1}\n'.format(k+1, ans))

f.close()
f_out.close()
