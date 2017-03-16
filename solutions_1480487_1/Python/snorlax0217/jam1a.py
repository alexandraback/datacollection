def sol1(L, N):
    X = 0.0
    for i in L:
        X += i
     
    X_ = X *2
    
    ret = ""
    
    avg =  X_ / N
    
    for i in L:
        if i > avg:
            X_ -= i
            N -= 1
    avg = X_ / N
        
    for i in L:

        y = (avg - i) / (X)
        
        if y <= 0:
            y = 0

       
        ret += " " + str(y * 100)
    
    return ret




if __name__ == '__main__':
    
    f = open("A-large.in",'r')
    num = f.readline()
    
    t = open('output.txt','w')
    
    for i in range(int(num)):
    
        s = f.readline()
        l = s.strip().split()
        L = []
        
        
        for j in l:
            L.append(float(j))

        N = float(L[0])
        ll = list(L[1:])

        t.write("Case #" + str(i+1) + ":" + sol1(ll, N) + "\n")
        
    f.close()
    t.close()
        