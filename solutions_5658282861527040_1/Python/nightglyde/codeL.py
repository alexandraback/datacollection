f = open("input.txt", "rU")
cases = int(f.readline().strip())
results = ""
for case in range(cases):
    line = f.readline().split()
    a = int(line[0])
    b = int(line[1])
    k = int(line[2])
    if (k > a) or (k > b):
        count = a*b
    else:
        count = k*a+k*b-k*k
        for aa in range(k,a):
            for bb in range(k,b):
                if aa&bb < k:
                    count += 1
    results += "Case #{}: {}\n".format((case+1),count)
    
f.close()
results = results.strip()

o = open("output.txt", "w")
o.write(results)
o.close()
