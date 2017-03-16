def main(filein):
    f = open(filein, "r")
    outname = filein.split(".")[0] + "OUT.txt"
    g = open(outname, "w")

    count = -1
    pair = []
    for line in f:
        count += 1
        if count == 0:
            continue
        pair.append(line)
        if len(pair) == 1:
            count -= 1
            continue
        elif len(pair) == 2:
            newline = "Case #" + str(count) + ": " + code(pair) + "\n"
            g.write(newline)
            pair = []
    
    f.close()
    g.close()
    
def code(pair):
    for i in range(2):
        if pair[i][-1] == "\n":
            pair[i] = pair[i][:-1]
    A, B = [float(x) for x in pair[0].split(" ")]
    ps = [float(x) for x in pair[1].split(" ")]
    prods = [1]
    for p in ps:
        prod = p * prods[0]
        prods.insert(0,prod)
    immediately = B + 2
    keepTyping = (B - A + 1) + ((1 - prods[0]) * (B + 1))
    best = min(immediately, keepTyping)
    for n in range(1, int(A) + 1):
        backN = (n + n + (B - A) + 1) + ((1 - prods[n]) * (B + 1))
        best = min(best, backN)
    answer = "%6f" % best
    return answer