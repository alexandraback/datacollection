# len - len(x)
# dict = {}


# main()

n = int( input() )
for i in range(n):
    values = raw_input().split()
    a = int( values[0] )
    b = int( values[1] )
    # print "read a", a, " b", b
    pbb = []
    cumpbb = []
    values = raw_input().split()
    prevfactor = 1

    for j in range(a):
        p = float( values[j] )
        pbb.append(p)
        newfactor = p * prevfactor
        cumpbb.append( newfactor )
        prevfactor = newfactor

    # print "-----------------" 
    # print a,b,pbb,cumpbb
    # print "-----------------" 

    expected = 0
    minexpected = 999
    for j in range(a):
        expected = (b-a+1)+2*j + (1-cumpbb[a-1-j])*(b+1)
        # print "expected ", j, " = ", expected
        if expected < minexpected:
            minexpected = expected
            # print "minexpec ", j, " = ", minexpected
    if a+b+1 < minexpected:
        minexpected = a+b+1
        # print "minexpec ", a, " = ", minexpected

    if 1+b+1 < minexpected:
        minexpected = 1+b+1
        # print "minexpec ", "ENTER", " = ", minexpected

    print "Case #"+str(i+1) + ":", minexpected

