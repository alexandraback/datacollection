import sys

def get_line():
    return sys.stdin.readline()

def get_ints():
    return [int(i) for i in get_line().split()]

tmult = [[], [0, 1, 2, 3, 4], [0, 2, -1, 4, -3], [0, 3, -4, -1, 2], [0, 4, 3, -2, -1]]
tdiva = [[], [0, 1, 2, 3, 4], [0, -2, 1, -4, 3], [0, -3, 4, 1, -2], [0, -4, -3, 2, 1]]
lit = {'i': 2, 'j': 3, 'k': 4}

def mult(a, b):
    pos = (a<0) == (b<0)
    res = tmult[abs(a)][abs(b)]
    return res if pos else -res
    
    
def diva(a, b):
    pos = (a<0) == (b<0)
    res = tdiva[abs(a)][abs(b)]
    return res if pos else -res

def get(tab, index):
    return tab[index % len(tab)]

def run(rep, lin):
    slen = len(lin)
    tab=[]
    for c in lin:
        tab.append(lit[c])
    
#    print(slen, rep)
        
    mu = 4 if (rep < 8) else 2
        
    r1 = 1
    r3 = 1
    for i in range(slen * (rep % 4)):
        r3 = mult(r3, get(tab, i))
        
    for p1 in range(1, min(slen * mu, slen * rep - 1) + 1):
        r1 = mult(r1, get(tab, p1 - 1))
        r2 = 1
        r3 = diva(get(tab, p1 - 1), r3)
        t3 = r3
        if r1!=2:
            continue
        for p2 in range(p1 + 1, min(p1 + 1 + slen * mu, slen * rep - 1) + 1):
            r2 = mult(r2, get(tab, p2 - 1))
            t3 = diva(get(tab, p2 - 1), t3)
            
            if mu==4 and (r1==2 and r2==3 and t3==4) or mu==2 and (r1*r2*t3)==24:
                #print(p1, p2, r1, r2, t3)
                return True
    
    return False
            


for e,n in enumerate(range(get_ints()[0])):
    slen, rep = get_ints()
        
    lin = get_line().strip()
    
    res = run(rep, lin)    
    print("Case #%i: %s" % (e+1, "YES" if res else "NO"))
                