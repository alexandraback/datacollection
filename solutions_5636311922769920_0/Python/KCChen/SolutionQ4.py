lines=raw_input()

for line_idx in xrange(1,int(lines)+1):

    K,C,S=[int(s) for s in raw_input().split(" ")]
    
    
    if K==1:
    
        print "Case #{}: ".format(line_idx)+"1"

    elif C==1:
        if S<K:
            print "Case #{}: ".format(line_idx)+"IMPOSSIBLE"
            continue
        print "Case #{}: ".format(line_idx)+" ".join([str(i) for i in range(1,K+1)])
    
    else:
        if S<K-1:
            print "Case #{}: ".format(line_idx)+"IMPOSSIBLE"

            continue
     
        print "Case #{}: ".format(line_idx)+" ".join([str(i) for i in range(2,K+1)])
    
