f=open("test3c.in", "r")
n_test=int(f.readline())

def compute(C,F,X,prod):
    fprod=prod+F
    result=0
    while not(X/prod < C/prod) and not( C/prod+X/fprod>X/prod):
        #print(prod)
        result+=C/prod
        prod+=F
        fprod=prod+F
    return result+X/prod

for i in range(n_test):
    (C,F,X) = tuple(map(float, f.readline().split(" ")))
    result=compute(C,F,X,2.0)
    w=open("result.txt", "a")
    s="Case #"+str(i+1)+": "+str(result)
    w=open("result.txt", "a")
    w.write(s+"\n")
    w.close()
f.close()
