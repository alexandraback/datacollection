with open('input.in') as fi:

    outfile = open('output.out','w')
    
    cases = int(fi.readline())
    print cases
    for case in range(1,cases+1):
        a,n = [int(aa) for aa in fi.readline().split()]
        motes = [int(aa) for aa in fi.readline().split()]
        motes.sort()
#        print a,n
#        print motes
        
        if a==1:
            print "Case #%d: %d" % (case,n)
            outfile.write("Case #%d: %d\n" % (case,n))
            continue
        
        costs = []
        for mote in motes:
            step_cost = 0
            while mote >= a:
                a += a-1
                step_cost += 1
            a += mote
            costs.append(step_cost)
        print costs
#        print "SDFASDFA"
        
        min = n
        for step in range(n):
            total_cost = sum(costs[0:step+1]) + n - step - 1
            if total_cost < min:
                min = total_cost
        
        print "Case #%d: %d" % (case,min)
        outfile.write("Case #%d: %d\n" % (case,min))
        
