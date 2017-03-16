
f = open("C-small-attempt0.in")
w = open("C-small.out.txt", 'w')
T = int(f.readline().strip())
for t in range(1, T+1):
    line = f.readline().strip()
    values = line.split(" ")
    A = values[0]
    B = values[1]
    a = int(A)
    b = int(B)
    count = 0
    for i in range(b, a-1, -1):
        number = str(i)
        template = number + number
        length = len(number)
        vars = []
        for j in range(1, length):
            var = template[j: j+length]
            if var < number and var>=A and var not in vars:
                vars.append(var)
                count+=1
    print "Case #" + str(t) + ": " + str(count)
    w.write("Case #" + str(t) + ": " + str(count) + "\n")
f.close()
w.close()
