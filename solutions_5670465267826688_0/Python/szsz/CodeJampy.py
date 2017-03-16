


f = {('1','1'):('1',1),
     ('1','i'):('i',1),
     ('1','j'):('j',1),
     ('1','k'):('k',1),
     ('i','1'):('i',1),
     ('i','i'):('1',-1),
     ('i','j'):('k',1),
     ('i','k'):('j',-1),
     ('j','1'):('j',1),
     ('j','i'):('k',-1),
     ('j','j'):('1',-1),
     ('j','k'):('i',1),
     ('k','1'):('k',1),
     ('k','i'):('j',1),
     ('k','j'):('i',-1),
     ('k','k'):('1',-1)}


def solve(sr):
    t = [int(i) for i in sr.readline().split(' ')]
    v = sr.readline()
    s = ('1',1)
    isi = False
    isk = False
    time = 10
    if t[1] < time:
        time = t[1]
    for k in range(time):
        for i in range(t[0]):
            n = f[(s[0],v[i])]
            s = (n[0], n[1] * s[1])
            if s == ('i',1):
                isi = True
            if s == ('k',1) and isi:
                isk = True
    if not isk:
        return "NO"
    s = ('1',1)
    for i in range(t[0]):
        n = f[(s[0],v[i])]
        s = (n[0], n[1] * s[1])
    if s == ('1', 1):
        return "NO"
    if s == ('1', -1):
        if t[1] % 2 == 1:
            return "YES"
        else:
            return "NO"
    if t[1] % 4 == 2:
        return "YES"    
    return "NO"




sr = open("D:\\in.in", 'r')
sw = open("D:\\out.out", 'w')

T = int(sr.readline())

for case in range(T):
    sw.writelines("Case #{}: {}\n".format(case + 1, solve(sr)))
    print(case)
sr.close()
sw.close()
