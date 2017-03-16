import sys

num_cases = int( sys.stdin.readline() )

for case in range( 1, num_cases+1 ):
    inputs = map( int, sys.stdin.readline().split() )
    N = inputs[0]
    S = inputs[1]
    p = inputs[2]
    scores = inputs[3:]
    num_excede = 0
    for score in scores:
        if score == 0 or score == 1:
            if score >= p:
                num_excede += 1
            continue
        if score == 2:
            if 1 >= p:
                num_excede += 1
            elif 2 >= p and S > 0:
                num_excede += 1
                S -= 1
            continue
            
        
        if score % 3 == 0:
            poss_max1 = score/3
            if poss_max1 >= p:
                num_excede += 1           
            elif poss_max1 + 1 >= p and S > 0:
                num_excede += 1
                S -= 1
        elif score % 3 == 1:
            poss_max = score/3 + 1
            if poss_max >= p:
                num_excede += 1            
        else:
            poss_max1 = score/3 + 1
            if poss_max1 >= p:
                num_excede += 1
            elif poss_max1 + 1 >= p and S > 0:
                num_excede += 1
                S -= 1
    print "Case #%s: %s" % (case, num_excede)
                 
            
        