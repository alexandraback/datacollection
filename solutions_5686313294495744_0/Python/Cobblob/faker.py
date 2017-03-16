from sets import Set

def solve(l):
    fake = 0
    for i, n in enumerate(l):
        first = Set([])
        second = Set([])
        for j, k in enumerate(l):
            if j != i:
                r, z = k.split(' ')
                z = z.replace('\n', '')
                first.add(r)
                second.add(z)
        a, b = n.split(' ')
        b = b.replace('\n', '')
        if a in first and b in second:
            fake +=1
    return fake

def main():
    f = open("input.txt", 'r')
    lines = f.readlines()
    f.close()

    outFile = open("out.txt", 'w')
    numSheets = int(lines[0])
    ln = 0
    for sheet in range(numSheets):
        ln += 1
        num = int(lines[ln])
        l = lines[ln+1: ln+num+1]
        print l
        ln += num
        out = "Case #"+str(sheet + 1)+": " + str(solve(l))+"\n"
        outFile.write(str(out))


main()
