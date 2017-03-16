import sys

def printerr(*v):
    print(*v, file=sys.stderr)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    n = int(input())
    naomi = [float(x) for x in input().split()]
    ken = [float(x) for x in input().split()]
    
    tot = naomi + ken
    tot.sort(reverse=True)
    score = 0; acc = 0;
    for x in tot :
        if x in naomi : 
            acc += 1
        else : 
            acc -= 1
        score = max(score, acc)
    
    naomi.sort()
    ken.sort()
    #printerr(naomi)
    #printerr(ken)
    dscore = 0
    while len(ken) > 0 :
        while len(ken) > 0 and naomi[0] < ken[0] :
            naomi.pop(0)
            ken.pop()
        while len(ken) > 0 and naomi[0] > ken[0] :
            naomi.pop(0)
            ken.pop(0)
            dscore += 1
        
    return '%d %d'%(dscore, score)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
