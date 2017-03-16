data_in = open("A-large.in", "r")
data_out = open("Problem.out", "w")

T = int(data_in.readline())

for t in xrange(T):
    data_out.write("Case #%d: "%(t+1))
    args = data_in.readline().split()
    R = int(args[0])
    C = int(args[1])
    W = int(args[2])
    
    y = C / W
    r = C - y*W
    y *= R
    o = W - r
    y += o-1
    y += W-o
    if r > 0:
        y += 1
    
    data_out.write("%d\n"%(y))
        

data_in.close()
data_out.close()
