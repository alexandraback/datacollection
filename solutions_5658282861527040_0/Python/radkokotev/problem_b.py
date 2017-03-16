filename = raw_input("Name of file: ")
f = open(filename, "r")
o = open(filename + ".out", "w")


T = int(f.readline()[:-1])

## Code starts here
for t in range(1, T + 1):
    line = [int(x) for x in f.readline()[:-1].split(" ")]
    total = 0
    for i in range(line[0]):
        for j in range(line[1]):
            cur = i & j
            if cur < line[2]:
                total += 1
    o.write("Case #%d: %d\n" %(t, total))            
    
## code ends here

o.close()
f.close()
