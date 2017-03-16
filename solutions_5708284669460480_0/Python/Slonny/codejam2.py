from collections import Counter

T = int(raw_input())  
for t in xrange(T):
    K, L, S = map(int, raw_input().split(' '))  
    keyboard = list(raw_input())
    target = list(raw_input())
    
    ans=0
    
    overlap = L
    for i in xrange(1, L):
        if target[i:]==target[0:-i]:
            overlap = i
            break
    max_banana = (S - L)/overlap + 1
       
    p=float(1)
    for target_l in target:
        target_c = keyboard.count(target_l) 
        if target_c == 0:
            break
        else:
            p = p * target_c / K
            
            
    ans =  round(max_banana - p * max_banana, 6)       
        
    print "Case #%d: %s" % (t+1, ans)
  