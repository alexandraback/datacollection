
def solve(n):
    #print n
    sn = str(n)
    l = len(sn)
    sn = list(sn)
    
    for i in range(l // 2, l):
        sn[i] = '0'
    sn[l - 1] = '1'
    sn = ''.join(sn)
    if (int(sn) > n):
        return solve(n - 1) + 1
        
    nn = int(sn[::-1])
    ret = n - int(sn)
    if (nn == 1):
        return ret + 1
    if (nn < int(sn)):
        ret += 1
    
    if (nn > 1 and nn == int(sn)):
        ret += 2
        nn -= 2
    ret += solve(nn)
    return ret

#A-small-attempt0.in
fin = open("A-large.in", "r")
fout = open("out.txt", "w")

T = int(fin.readline())

for ca in range(T):
    n = int(fin.readline())
    fout.write("Case #" + str(ca + 1) + ': ' + str(solve(n)) + '\n')

fin.close()
fout.close()
