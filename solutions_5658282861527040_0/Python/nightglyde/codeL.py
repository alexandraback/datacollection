f = open("input.txt", "rU")
cases = int(f.readline().strip())
results = ""
for case in range(cases):
    line = f.readline().split()
    a = int(line[0])
    b = int(line[1])
    k = int(line[2])
    count = 0
    for aa in range(a):
        for bb in range(b):
            if aa&bb < k:
                count += 1
    results += "Case #{}: {}\n".format((case+1),count)
    
f.close()
results = results.strip()

o = open("output.txt", "w")
o.write(results)
o.close()
