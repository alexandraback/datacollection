def read_file():
    file = open("A-large.in")
    out = open("OutputA.txt", 'w')
    T = int(file.readline())
    for t in range(1, T+1):
        logs = [1/2**x for x in range(0, 41)]
        out.write("Case #" + str(t) + ": ")
        [P, Q] = [int(x) for x in file.readline().split("/")]
        if (P/Q) % (1/2**40) != 0.0:
            out.write("impossible\n")
        else:
            for i in range(len(logs)):
                log = logs[i]
                if log <= (P/Q):
                    out.write(str(i) + "\n")
                    break
            #What is the highest factor
            #print(logs)

        
    out.close()

read_file()
