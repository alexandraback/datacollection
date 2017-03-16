inp = open("in3.txt", "r")
out = open("out4.txt","w")
T= int((inp.readline()).rstrip())
for i in range(T):
    args=((inp.readline()).rstrip()).split()
    K=int(args[0])
    C=int(args[1])
    S=int(args[2])
    if K==S:
        out.write("Case #" + str(i+1) + ": ")
        for j in range(S-1):
            out.write(str(j+1)+" ")
        out.write(str(S)+"\n")