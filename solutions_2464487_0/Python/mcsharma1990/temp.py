def solve(r, t):
    u = 10000000000000000000
    l = 1
    while (u-l > 1):
        k = (u+l)//2;
        if 2*r*k+k*(2*k-1) <= t:
            l = k;
        else:
            u = k
    return l

f = open("temp.txt", "r")
w = open("out.txt", "w")
print(f)
s = f.readline()
print(s)
T = int(s)

for i in range(1, T+1):
    (r, t) = f.readline().split();
    r = int(r)
    t = int(t)
    ans = solve(r, t)
    w.write('Case #' +str(i)+": "+str(ans)+"\n")
w.close()
f.close()
    
    
    
