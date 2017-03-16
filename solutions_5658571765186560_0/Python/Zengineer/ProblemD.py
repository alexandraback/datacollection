data_in = open("D-small-attempt1.in", "r")
data_out = open("ProblemD.out", "w")

T = int(data_in.readline())

for t in xrange(T):
    data_out.write("Case #%d: "%(t+1))
    arg = data_in.readline().split()
    X = int(arg[0])
    R = int(arg[1])
    C = int(arg[2])

    maxs = max(R,C)
    mins = min(R,C)

    if X>6 or (R*C)%X!=0 or X>maxs or (X>2 and X==(R*C)) or (X==4 and mins==2) or ((X==5 or X == 5) and 1<mins<4):
        data_out.write("RICHARD\n")
        continue
    data_out.write("GABRIEL\n")
    

data_in.close()
data_out.close()
