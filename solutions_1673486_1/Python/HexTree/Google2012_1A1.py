f = open("data.txt", 'r')
g = open("data1.txt", 'w')

line = f.readline()
n = int(line)
for t in range(1, n+1):
    line = f.readline()
    integers = [int(x) for x in line.split()]
    a, b = integers[0], integers[1]
    line = f.readline()
    probs = [float(x) for x in line.split()]
    result = 2.0 + b
    multiple = 1.0
    for i in range(a-1, -1, -1):
        multiple *= probs[a-i-1]
        expKeepGoing = b - a + 2*i + 1 + (b+1)*(1-multiple)
        if expKeepGoing < result:
            result = expKeepGoing
    sresult = "%0.6f" % result
    string = "Case #" + str(t) + ": " + sresult + '\n'
    g.write(string)

f.close()
g.close()
