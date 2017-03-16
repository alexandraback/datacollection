from sys import argv
script, file_name = argv

in_file = open(file_name, 'r')

for t in range(int(in_file.readline())):
    d = [int(j) for j in in_file.readline().split(' ')]
    a, b = d[0], d[1]
    p = [float(j) for j in in_file.readline().split(' ')]
    
    e = [b+2]
    
    prod = 1
    for pi in p: prod *= pi
    e.append(prod*(b-a+1) + (1-prod)*(2*b-a+2))
    
    c = 1
    p.reverse()
    for pi in p:
        prod /= pi
        e.append(prod*(b-a+1+2*c) + (1-prod)*(2*b-a+2+2*c))
        c += 1
    
    
    print "Case #%d: %.6f" % (t+1, min(e))

in_file.close()
