
def allcorrect(p):
    f = 1
    for x in p:
        f *= float(x)
    return f

def allcorrect_k(p,k):
    f = 1
    for x in p[:k]:
        f *= float(x)
    return f

def somewrong(p):
    return 1 - allcorrect(p)

def solve(t):
    a,b = [int(x) for x in raw_input().strip().split()]
    #print a,b
    p = [float(x) for x in raw_input().strip().split()]
    
    ap = allcorrect(p)

    c1 = (ap*(b-a+1) +
          (1-ap) * (b - a + 1 + b + 1))

    #print ap

    for i in range(a+1):
        if i==0:
            continue
        aap = allcorrect_k(p,a-i)

        #print aap
        
        c2 = ((aap*(2*i + b - a + 1)) +
              (1 - aap)*(2*i + b - a + 1 + b + 1))
              
        if c2 < c1:
            c1 = c2

    if b+2 < c1:
        c1 = b+2
        
    print 'Case #%d: %.6f' % (t,c1)

def main():
    t = int(raw_input())
    for i in range(t):
        solve(i+1)

if __name__=='__main__':
    main()
