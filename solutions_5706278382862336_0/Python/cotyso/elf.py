
outFile = open("output.txt", "w")
#lines = list(open("input.txt"))
lines = list(open("A-small-attempt0.in"))

testCount = int(lines.pop(0))

for test in range(1, testCount+1):
    p, q = [int(x) for x in lines.pop(0).split(sep="/")]
    print(p, q)

    r = p/q
    
    level = 1
    first = -1
    for i in range(40):
        level /= 2
        if level <= r:
            if first == -1:
                first = i
            r -= level
    print(first+1, r)
    
    print("Case #{}: {}".format(test, first+1 if r == 0.0 else "impossible"))
    outFile.write("Case #{}: {}\n".format(test, first+1 if r == 0.0 else "impossible"))

outFile.close()