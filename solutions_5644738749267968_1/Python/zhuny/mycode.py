def do():
    count = input()
    for i in xrange(count):
        print "Case #%d:"%(i+1),
        calculate()

def war_opti(naomi,ken):
    L = len(ken)

    i,j = 0,0
    count = 0
    while i<L and j<L:
        if naomi[i] > ken[j]:
            j+=1
            count+=1
        else:
            i+=1
            j+=1
    return count

def deceit_war(naomi,ken):
    i,j1,j2 = 0,0,len(ken)-1
    
    count = 0
    while i<len(naomi) and j1<=j2:
        if naomi[i] < ken[j1]:
            i+=1
            j2-=1
        else:
            count+=1
            i+=1
            j1+=1
    return count

def calculate():
    L = input()
    naomi = map(float,raw_input().split())
    ken = map(float,raw_input().split())

    naomi.sort()
    ken.sort()
    
    print deceit_war(naomi,ken),war_opti(naomi,ken)


    

if __name__ == '__main__':
    do()
