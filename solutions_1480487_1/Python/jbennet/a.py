import sys

def process_cases(data):
    cases = data[0]
    out = open(sys.argv[1] + '.txt', 'w')
    
    for i in range(1, len(data)):
        case = map(float, data[i].split())[1:]
        result = []
        total = sum(case)
        n = len(case)
        
        available = 2 * total
        minpoints = total * 2 / n

        for j in case:
            if j > minpoints:
                available -= j
                n -= 1

        for j in case:
            t = 0
            if j < minpoints:
                t = 100. * (available / n - j) / total
            result.append('%.6f' % (t))
        
        r = ' '.join(result)
        out.write("Case #%d: %s\n" % (i, r))

    out.close()

def readdata(filename):
    data = []
    f = open(filename, 'r')
    for line in f:
        data.append(line.strip())
    return data

if len(sys.argv) < 2:
    print 'Usage:', sys.argv[0], '<input_file_name>'
else:
    data = readdata(sys.argv[1])
    process_cases(data)
