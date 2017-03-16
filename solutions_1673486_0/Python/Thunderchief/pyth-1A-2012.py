fi = open("A-small-attempt0.in", "r")
n = int(fi.readline())
for l in range(0, n):
    [a, b] = list(map(int, fi.readline().split()))
    prob = list(map(float, fi.readline().split()))
    k = 0
    #expected keystrokes if you keep typing
    pr = 1
    for i in prob:
        pr *= i #the probability of typing everything correctly
    exp = (b-a+1)*pr + (b-a+b+2)*(1-pr)
    #expected keystrokes if you press bksp some number of 
    ex = exp
    for i in range(1, a+1):
        pr = 1
        for j in range(0, len(prob)-i):
            pr *= prob[j] #the probability of typing everything correctly
        e = (b-(a-i)+1)*pr + (b-(a-i)+b+2)*(1-pr) + i    
        #print(e)
        if e < ex:
            ex = e
    print("Case #" + str(l) + ": " + str(float(b+2) if ex > b+2 else float(ex)))