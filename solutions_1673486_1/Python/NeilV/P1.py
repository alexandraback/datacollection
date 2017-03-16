def all_right(probs):
    ret = 1
    for p in probs:
        ret *= p
    return ret

data = open("P1.txt")
cases = int(data.readline().strip())
out = open("P1.out","w")

for case in range(cases):
    a,b = map(int,data.readline().split())
    prob = map(float,data.readline().split())
    right = all_right(prob)
    
    '''for a in range(2):
        if typed == 1:
            #Y or N
            p = prob[0]
            mistake = p*(b-a+b+2)
            correct = (1-p)*(b-a+1)
            keep_typing = mistake+correct
            
        for b in range(2):
            for c in range(2):
                pass'''
    
    keep_typing = right*(b-a+1) + (1-right)*(b-a +b+2)
    enter = b+2
    backs = []
    count=0
    for i in reversed(range(a)):
        count += 1
        right/= prob[i]
        backs.append(right*(b-a+2*count+1) + (1-right)*(b-a+2*count+b+2))
        
    #print keep_typing
    #print backs
    #print enter
    ans = min(backs+[keep_typing,enter])
    #print ans
    #print ""
    out.write("Case #%i: %.9f\n" %(case+1,ans))