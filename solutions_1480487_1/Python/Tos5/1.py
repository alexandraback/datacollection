f = open('A-large.in', 'r')
o = open('A-large.out', 'w')

num = int(f.readline())

for a in range(0, num):
    line = f.readline()
    data = line.split()
    numval = float(data[1])
    data = data[1:]
    for b in range(0, len(data)):
        data[b] = float(data[b])
    output = []
    n = len(data)
    add = sum(data)
    for b in range(0, len(data)):
        output.append((sum(data[0:b] + data[b+1:]) - (n-1) * data[b] + add)/(n * add)* 100)
    invalid = []
    for b in range(0, len(data)):
        if output[b] < 0:
            invalid.append(b)
    newoutput = []
    for x in range(0,len(output)):
        if output[x] >= 0:
            newoutput.append(data[x])

    insum = 0

    for x in invalid:
        insum += data[x]
        
    if min(output) < 0:
        output = []
        for b in range(0, len(data)):
            if b in invalid:
                output.append(str(float(0)))
            else:
                output.append((sum(data[0:b] + data[b+1:]) - insum - (n-1-len(invalid)) * data[b] + add)/((n-len(invalid)) * add)* 100)
        

    string = ""
    for x in output:
        string += str(x) + " "
    string += "\n"
    o.write("Case #" + str(a+1) + ": " + string)

f.close()
o.close()
