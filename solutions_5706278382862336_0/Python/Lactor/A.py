

def gcd(a,b):
    if a==1:
        return 1
    if a==0:
        return b
    else:
        return gcd(b%a, a)


N = input()

for z in range(N):
    values = raw_input()
    values = values.split("/")
    num = int(values[0])
    dem = int(values[1])
    
    common = gcd(num, dem)
    num/=common
    dem/=common

    gen = 0
    final_gen = -1
    while dem%2 == 0:
        gen+=1
        dem/=2
        if final_gen == -1 and num > dem:

            final_gen = gen
            

    if dem == 1:
        if final_gen == -1:
            final_gen = gen
        print 'Case #%d: %d' %( z+1,final_gen)
    else:
         print "Case #%d: impossible" %(z+1)


    
