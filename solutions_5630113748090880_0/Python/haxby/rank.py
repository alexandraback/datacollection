def rank(lsts):
    odds = []
    x = [i for j in lsts for i in j]
    for i in set(x):
        if x.count(i)%2:
            odds.append(i)
    return sorted(odds)
    
            
        

    
n = int(raw_input())
for i in range(n):
    num = eval(raw_input())
    lsts=[]
    for j in xrange(2*(num)-1):
        lst = map(int, raw_input().split())
        lsts.append(lst)
    ranks = rank(lsts)
    print "Case #{0}: {1}".format(i+1, " ".join(map(str, ranks)))
    
