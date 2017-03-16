import math
inp = raw_input()
inp = inp.split('\n')
T = int(inp[0])
case = 0
while T:
    case = case + 1
    elfness = inp[case]
    elfness = elfness.split('/')
    P = int(elfness[0])
    Q = int(elfness[1])
##    print P,Q
    temp = Q
    gen = 0
    while temp%2 == 0:
        temp = temp/2
        gen = gen + 1
    if gen == 0:
        print 'Case #'+str(case)+': impossible'
    else:
        if P%temp != 0:
            print 'Case #'+str(case)+': impossible'
        else:
            temp1 = P/temp
            gen1 = 0
            while temp1%2 == 0:
                temp1 = temp1/2
                gen1 = gen1 + 1
            p2wr = gen - gen1
##            print 'Case #'+str(case)+':',answr
            P = temp1
            Q = 2**(p2wr)
##            print P,Q
            answr = 1
            tempr = Q
            while tempr > 2*P:
                answr = answr + 1
                tempr = tempr/2
            print 'Case #'+str(case)+':',answr
    T = T - 1
