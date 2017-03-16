from sys import argv
script, file_name = argv

in_file = open(file_name, 'r')

for i in range(int(in_file.readline())):
    d = [int(j) for j in in_file.readline().split(' ')]
    a, b = d[0], d[1]
    y = 0
    for n in range(a, b):
        m = n/10 + (n%10)*10**(len(str(n))-1)
        while m != n:
            if m > n and m <= b: y += 1
            m = m/10 + (m%10)*10**(len(str(n))-1)
        
    print "Case #%d: %d" % (i+1, y)

in_file.close()
