with open("D-small-attempt0.in", "r") as data:
    cases = int(data.readline())
    with open("D-small-attempt0.out", "w") as result:
        for i in range(cases):
            seq_len, comp, tiles = (int(x) for x in data.readline().split(" "))
            result.write("Case #" + str(i+1) + ":")
            for j in range(1, tiles+1):
                result.write(" " + str(j))
            result.write("\n")
          
