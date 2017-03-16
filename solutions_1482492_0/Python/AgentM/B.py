import math

IN = open('BSmallIn.txt','r')
OUT = open('BSmallOut.txt','w')
tc = int(IN.readline())
for i in xrange(tc):
    answer = 0
    data = (IN.readline().split(' '))
    distance = float(data[0])
    total_points = int(data[1])
    total_accs = int(data[2])
    xi = []
    ti = []
    for j in xrange(total_points):
        data = (IN.readline().split(' '))
        ti.append(float(data[0]))
        xi.append(float(data[1]))
    data = (IN.readline().split(' '))
    accs = []
    for j in xrange(total_accs):
        accs.append(float(data[j]))
    #print ti
    #print xi

    if(total_points == 2):
        m = (xi[1]-xi[0]) / (ti[1] - ti[0])
        b = xi[0] - m * ti[0]
        #print "X = %1.6f X + %1.6f" % (m,b)
        #print accs
    else:
        m = 1.0
        b = distance
        
    print "Case #%i" % (i + 1)
    OUT.write("Case #%i:\n" % (i + 1))

    other_cars_time = (distance - b)/m
    
    for j in xrange(total_accs):
        colls = (m + math.sqrt(m**2 + 2*accs[j]*b))/accs[j] #only neeed right one?
        #colls.append((m - math.sqrt(m**2 + 2*accs[j]*b))/accs[j])
        #print colls

        your_cars_time = math.sqrt(2*distance/accs[j])

        if(colls <= other_cars_time):
            answer = other_cars_time
        else:
            answer = your_cars_time

        print answer
        OUT.write("%1.6f\n" % (answer))
OUT.close()
    
    
