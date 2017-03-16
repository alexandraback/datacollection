data_in = open("A-small-attempt0.in", "r")
data_out = open("ProblemA.out", "w")

T = int(data_in.readline())

for i in xrange(T):
    arg = data_in.readline().split()
    Smax = int(arg[0])
    shyness = [int(x) for x in arg[1]]
    n = shyness[0]
    guest = 0

    for j in xrange(1, Smax+1):
        current = shyness[j]
        prereq = shyness[j-1]
        diff = j - prereq
        if n < j:
            guest += j-n
            n = j
        n += shyness[j]
    
    data_out.write("Case #%d: %d\n"%(i+1, guest))

data_in.close()
data_out.close()
