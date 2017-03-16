file1 = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\proC.txt","r")
file = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\resultC.txt","w")

def mp():
    global file1  
    return map(int,file1.readline().split())
def ip():
    global file1  
    return file1.readline()
def it():
    global file1  
    return int(file1.readline())
def lt():  
    global file1
    return list(map(int,file1.readline().split()))
def ptlist(l): 
    global file
    file.write(' '.join(map(str,l)))
#"Case #d: "
T = it()
for i in range(T):
    n = it()
    a = lt()
    for r in range(n):
        a[r] -= 1
    b = [[i for i in range(n) if a[i] == k] for k in range(n)]
    maxx = 0
    maxlen = []
    
    def backtracking():
        global L
        global a,b,maxx,maxlen
        k = L[-1]
        s = []
        for i in b[k]:
            if not i in L:
                s.append(i)
        if a[k] in L and len(s) == 0:  
            if (a[L[0]] == L[1] or a[L[0]] == L[-1]) and (a[L[-1]] == L[0] or (len(L)>=2 and a[L[-1]] == L[-2])) and len(L) > maxx:
                maxlen = list(L)
                maxx = len(L)
        else:
            if len(L) <= 1 or L[-2] != a[k]:
                s = [a[k]]
            for t in s:
                L.append(t)
                backtracking()
                L.pop()
    for j in range(n):
        L = [j]
        backtracking()
    print("Case #%d: %d" % (i+1,maxx))
    file.write("Case #%d: %d\n" % (i+1,maxx))
            
        
    

