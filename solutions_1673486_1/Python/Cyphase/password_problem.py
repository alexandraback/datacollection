import sys
import decimal

import psyco
psyco.full()

D = decimal.Decimal
#D = float
decimal.getcontext().prec = 50

def keystrokes(plist, backspaces):
    pass

num_cases = int(sys.stdin.readline())

for t in range(1, num_cases+1):
    already_typed, pass_len = map(int, sys.stdin.readline().split())
    plist = [D(x) for x in sys.stdin.readline().split()]
    
    exs = set()
    exs.add(pass_len + 2) # give up possibility
    
    p_prod = 1
    
    # backspaces
    for b in xrange(already_typed, -1, -1):
        ## remaining before backspaces, including enter
        #if b%1000==0: print b
        
        if b == already_typed:
            pass
        else:
            p_prod *= plist[already_typed-b-1]
        
        prob_correct = p_prod
        
        correct_ex = pass_len - already_typed + 1 + b + b
        incorrect_ex = correct_ex + pass_len + 1
        
        #prob_correct = reduce(lambda x,y:x*y, plist[:already_typed-b], D(1))
        
        #print '\tPC', prob_correct, 'plist', plist[:already_typed-b]
        
        exs.add(prob_correct * correct_ex + (1-prob_correct) * incorrect_ex)
        #print '\texs',prob_correct * correct_ex + (1-prob_correct) * incorrect_ex
        #exs.add((1-prob_correct) * incorrect_ex)
        #print (1-prob_correct) * incorrect_ex
    
    result = min(exs)
        
        
    
    sys.stdout.write("Case #%s: %s\n" % (t, result))
