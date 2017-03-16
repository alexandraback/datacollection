filename = "A-small-attempt2.in" # change later
f = open(filename)
T = int(f.readline())
for case in range(1,T+1):
    # print "Case# :" +str(case)
    s = f.readline()
    s = s.split()
    r = int(s[0])
    t = int(s[1])
    
    upper = t
    lower = 1
    old_n = t/2
    while True:
        if ( 2*old_n*old_n + old_n*(2*r-1) ) <= t:
            new_n =  (old_n + upper )/2
            # print "OK!"
            if new_n == old_n:
                # print "break. new_n = " + str(new_n)
                break
            lower = old_n
            old_n = new_n
        else:
            new_n = ( old_n + lower ) / 2
            # print "not OK!"
            if new_n == lower:
                # print "break. new_n = " +str(new_n)
                break
            upper = old_n
            old_n = new_n
    print "Case #" + str(case) + ": " + str(new_n)
    