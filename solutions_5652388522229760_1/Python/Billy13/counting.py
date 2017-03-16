inp = open("in.txt", "r")
out = open("out1.txt","w")
T= int((inp.readline()).rstrip())
for i in range(T):
    N=(inp.readline()).rstrip()
    pin=[0,0,0,0,0,0,0,0,0,0]
    lst=list(N)
    ar=int(N)
    met=2
    for l in lst:
        pin[int(l)]=1
    while sum(pin)!=10:
        n_ar=ar*met
        if n_ar==ar:
            break
        else:
            met+=1
            N=str(n_ar)
            lst=list(N)
            for l in lst:
                pin[int(l)]=1
    if sum(pin)!=10:
        out.write("Case #" + str(i+1) + ": INSOMNIA\n")
    else:
        out.write("Case #" + str(i+1) + ": " + str(n_ar) + "\n")
