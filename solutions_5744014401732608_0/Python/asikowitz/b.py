inp = open("B-small-attempt1.in","r")
out = open("b1.out","w")

def readline(f):
    return f.readline().strip()

n = int(readline(inp))

def make_ones(L,index):
    for i in range(len(L)-index):
        L[i+index] = 1

    return L

def inc(L,index):
    for i in range(len(L)-index):
        if L[i+index] == 0:
            L[i+index] = 1
            break
    return L

def make_n(L,n,index):
    count = 0
    for i in range(len(L)-index):
        if count < n:
            L[i+index] = 1
            count += 1

    return L

def to_string(L):
    ans = ""
    for i in range(len(L)):
        ans += str(L[i])

    return ans

for case in range(n):
    inputs = readline(inp).split(" ")
    b = int(inputs[0])
    m = int(inputs[1])
    
    L = [[0 for i in range(b)] for i in range(b)]
    for i in range(b-1):
        L[i][b-1] = 1
            
    c = 0
    conns = 1
    written = False
    
    while conns < m:
        if c > b-2:
            written = True
            out.write("Case #%d: %s\n" % (case+1,"IMPOSSIBLE"))
            break
        elif m >= conns + (b-c-2)*(1+c*(c-1)/2):
            L[c] = make_ones(L[c],c+1)
            conns += (b-c-2)*(1+(c)*(c-1)/2)
            c = c+1
        else:
            while m >= conns + (1+c*(c-1)/2):
                L[c] = inc(L[c],c+1)
                conns += 1+c*(c-1)/2
            if m != conns:
                written = True
                out.write("Case #%d: %s\n" % (case+1,"IMPOSSIBLE"))
                break
                
    if (not written):
        out.write("Case #%d: %s\n" % (case+1,"POSSIBLE"))
        for i in range(len(L)):
            out.write("%s\n" % to_string(L[i]))
inp.close()
out.close()
