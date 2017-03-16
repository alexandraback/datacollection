f = open('B-large.in', 'r')
f2 = open('output', 'w')
numCases = int(f.readline())
for c in range(0, numCases):
    n = int(f.readline())
    dic = {}
    miss = []
    for y in range(0, 2*n - 1):
        line = f.readline().split()
        for x in range(0, len(line)):
            try:
                dic[line[x]] += 1
            except:
                dic[line[x]] = 1
    for key, value in dic.iteritems():
        if(value % 2 == 1):
            miss.append(int(key))
    answer = "Case #" + str(c + 1) + ": "
    for item in sorted(miss):
        answer += str(item) + " "
    f2.write(answer + "\n")