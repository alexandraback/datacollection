import sys

f = open('A-large.in')
f_out = open('A-large.out', 'w')

T = int(f.readline())
for k in range(T):
    line = f.readline().split()
    R = int(line[0])
    C = int(line[1])
    W = int(line[2])
    ans = 0
    one = C-2*(W-1)
    if one <= 0:
        one = 1
    ans += one*(R-1)
    if W==C:
        ans+=W
    else:
        place = W
        while place<C:
            ans += 1
            place += W
        ans += W
    f_out.write('Case #{0}: {1}\n'.format(k+1, ans))

f.close()
f_out.close()
