with open("D-large.in", "r") as data:
    cases = int(data.readline())
    with open("D-large.out", "w") as result:
        for i in range(cases):
            seq_len, comp, tiles = (int(x) for x in data.readline().split(" "))
            result.write("Case #" + str(i+1) + ":")
            if tiles <= seq_len - comp:
                result.write(" IMPOSSIBLE")
            elif tiles == seq_len or tiles == seq_len - 1:
                for j in range(seq_len-tiles+1, seq_len+1):
                    result.write(" " + str(j))
            else:
                const = seq_len - tiles - 2
                for j in range(const*(seq_len**2) + (const+2)*seq_len - tiles + 1, const*(seq_len**2) + (const+2)*seq_len + 1):
                    result.write(" " + str(j))
            result.write("\n")
          
