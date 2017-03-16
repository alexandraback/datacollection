
for test in range(1, input() + 1):
    J, P, S, K = raw_input().split()
    J = int(J)
    P = int(P)
    S = int(S)
    K = int(K)

    JPcombination={}
    JScombination={}
    PScombination={}
    me = [1,1,1]

    l = []
    count = 0
    #if J == 1 and S == 1 and P == 1:
    #    l.append(str(me[0]) + " " + str(me[1]) + " " + str(me[2]))
    #    count = 1

    while True:
        if me[0] == J and me[1] == P and me[2] == S:
            break
        #print me
        #print JPcombination
        #print JScombination
        #print PScombination
        if (((JPcombination.get(str(me[0]) + " " + str(me[1])) == None) or (JPcombination[str(me[0]) + " " + str(me[1])] + 1 <= K)) and
            ((JScombination.get(str(me[0]) + " " + str(me[2])) == None) or (JScombination[str(me[0]) + " " + str(me[2])] + 1 <= K)) and
            ((PScombination.get(str(me[1]) + " " + str(me[2])) == None) or (PScombination[str(me[1]) + " " + str(me[2])] + 1 <= K))):

            count += 1
            l.append(str(me[0]) + " " + str(me[1]) + " " + str(me[2]))

            if JPcombination.get(str(me[0]) + " " + str(me[1])) == None:
                JPcombination[str(me[0]) + " " + str(me[1])] = 0
            if JScombination.get(str(me[0]) + " " + str(me[2])) == None:
                JScombination[str(me[0]) + " " + str(me[2])] = 0
            if PScombination.get(str(me[1]) + " " + str(me[2])) == None:
                PScombination[str(me[1]) + " " + str(me[2])] = 0

            JPcombination[str(me[0]) + " " + str(me[1])] += 1
            JScombination[str(me[0]) + " " + str(me[2])] += 1
            PScombination[str(me[1]) + " " + str(me[2])] += 1

        me[2] += 1

        if me[2] > S :
            me[2] = 1
            me[1] += 1
        if me[1] > P :
            me[1] = 1
            me[0] += 1


    if (((JPcombination.get(str(me[0]) + " " + str(me[1])) == None) or (JPcombination[str(me[0]) + " " + str(me[1])] + 1 <= K)) and
        ((JScombination.get(str(me[0]) + " " + str(me[2])) == None) or (JScombination[str(me[0]) + " " + str(me[2])] + 1 <= K)) and
        ((PScombination.get(str(me[1]) + " " + str(me[2])) == None) or (PScombination[str(me[1]) + " " + str(me[2])] + 1 <= K))):

        count += 1
        l.append(str(me[0]) + " " + str(me[1]) + " " + str(me[2]))

    print 'Case #' + str(test) + ": " + str(count)
    for i in l:
        print i
