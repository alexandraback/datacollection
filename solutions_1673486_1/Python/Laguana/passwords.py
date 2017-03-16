import scipy as sp


T = int(raw_input(''))
#T = 1
for t in range(T):
    line = raw_input('')
    A,B = map(int, line.split(' '))
    line = raw_input('')
    probs = sp.array(map(float, line.split(' ')))
#    A = int(99999*sp.rand())
#    B = 100000
#    probs = sp.rand(A)
    accum = sp.ones(len(probs)+1)

    for i in xrange(len(accum)):
        if i > 0:
            accum[i] = accum[i-1] * probs[i-1]

    required = B-A + 1 #best case: finish writing the password and hit enter
    giveup = B+2      #minimal worst case: give up, retype and hit enter
    answer = giveup
    
    prefix = 0
    while prefix < A:
        if probs[prefix] >= 1:
            prefix += 1
        else:
            break
    
    # prefix is now the guaranteed-correct prefix
    # Each step backwards costs 2; delete + retype    
    for i in xrange(len(accum)):
        # Delete all but i characters. This takes A-i keystrokes
        #   rewriting them doubles this
        # Then you need to do the remaining B-A + 1 keys
        v_right = (A-i)*2 + required
        # If you get it wrong, additional retype + enter
        v_wrong = v_right + B+1 
        # You are right if
        e = v_right * accum[i] + v_wrong * (1-accum[i])
#        print v_right, v_wrong, accum[i], e
        if e < answer:
            answer = e
        if answer <= required:
            break

    print "Case #%d: %f" % (t+1, answer)
