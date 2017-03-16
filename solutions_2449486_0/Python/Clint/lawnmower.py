from sys import argv
script, file_name = argv

in_file = open(file_name, 'r')

for t in range(int(in_file.readline())):
    d = [int(j) for j in in_file.readline().split(' ')]
    n, m = d[0], d[1]
    
    a = []
    for i in range(n): a.append([int(j) for j in in_file.readline().split(' ')])
    
    s = "YES"
    while n > 0 and s != "NO":
        changes = 0
        a_min = min([min(row) for row in a])
        #print a
        #print "a_min = %d: " % (a_min)
        temp_n = n
        for i in range(n-1, -1, -1):
            if a[i].count(a_min) == m:
                del a[i]
                temp_n -= 1
                changes += 1
        #print a
        a = [[row[i] for row in a] for i in range(m)]
        n, m = m, temp_n
        temp_n = n
        for i in range(n-1, -1, -1):
            if a[i].count(a_min) == m:
                del a[i]
                temp_n -= 1
                changes += 1
        n = temp_n
        #print a
        if changes == 0: s = "NO"
            
    print "Case #%d: %s" % (t+1, s)

in_file.close()
