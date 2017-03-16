f = open("B-large.in")
o = open("output-large.txt",'w')
t = int(f.readline())

def got_atleast_p(x, p):
    if x-p >= 2*p - 2 and x-p>=0:
        return True
    else:
        return False

def got_p_surprising(x, p):
    if x-p >= 2*p-4 and x-p>=0:
        return True
    else:
        return False
    
for i in range(1, t+1):
    params = f.readline().split(' ')
    n = int(params[0])
    s = int(params[1])
    p = int(params[2])
    points = params[3:]
    
    k = 0
    for x in points:
        x = int(x)
        
        if got_atleast_p(x, p):
            k += 1
        elif got_p_surprising(x, p) and s>0:
            k += 1
            s -= 1

    o.write("Case #"+str(i)+": "+str(k)+"\n")

f.close()
o.close()
            
            
    
    
