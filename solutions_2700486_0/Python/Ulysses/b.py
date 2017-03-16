import copy
from decimal import *
getcontext().prec = 7

filename = 'B-small-attempt4'

f = open(filename + '.in')

outfile = open(filename + '.out', 'w')


def percent(situation, prob, x, y, falling, gems):
    #print 'xxxxxxx',situation, x, y, gems
    if not falling and gems > 0:
        gems -= 1
        y_loc = 0
        while True:
            
            location =  (0, y_loc)
            if location not in situation:
                if location == (0, 0):
                    if x == 0 and y == 0:
                        
                        return 1
                    else:
                        new_sit = copy.deepcopy(situation)
                        new_sit[location] = None
                        return percent(new_sit, Decimal(1), x, y, False, gems)
                
                
                # hit a vertex will slide to left or right
                left_loc = location[0]-1, location[1]-1
                right_loc = location[0]+1, location[1]-1
                #print left_loc, right_loc
                
                left_full = left_loc in situation
                right_full = right_loc in situation
                
                if left_full and right_full:
                    if location[0] == x and location[1] == y:
                        return prob   # has to stay here
                    else:
                        new_sit = copy.deepcopy(situation)
                        new_sit[location] = None
                        return percent(new_sit, Decimal(prob), x,y, False, gems)
                elif left_full and not right_full:
                    #print 'goign right'
                    new_sit = copy.deepcopy(situation)
                    final_loc = right_loc
                    while True:
                        test_loc = final_loc[0]+1, final_loc[1]-1
                        #print test_loc
                        if test_loc[1] < 0: break
                        if test_loc not in new_sit:
                            final_loc = test_loc[:]
                        else:
                            break
                    new_sit[final_loc] = None
                    if final_loc[0] ==x and final_loc[1] ==y: return prob
                    return percent(new_sit, prob, x, y, False, gems)
                elif not left_full and right_full:
                    #print 'going left'
                    new_sit = copy.deepcopy(situation)
                    final_loc = left_loc
                    while True:
                        test_loc = final_loc[0]-1, final_loc[1]-1
                        if test_loc[1] < 0: break
                        if test_loc not in new_sit:
                            final_loc = test_loc[:]
                        else:
                            break
                    new_sit[final_loc] = None
                    if final_loc[0] ==x and final_loc[1] ==y: return prob
                    return percent(new_sit, prob, x, y, False, gems)
                else:
                    #print 'both'
                    # both likely
                    per = 0
                    new_sit = copy.deepcopy(situation)
                    final_loc = right_loc
                    while True:
                        test_loc = final_loc[0]+1, final_loc[1]-1
                        if test_loc[1] < 0: break
                        if test_loc not in new_sit:
                            final_loc = test_loc[:]
                        else:
                            break
                    new_sit[final_loc] = None
                    #print 'right final', final_loc
                    if final_loc[0] ==x and final_loc[1] ==y:
                        #print 'sdfaswwwwwwwwwwwwwwwwwwwwwww'
                        per += prob*Decimal(0.5)
                    else:
                        #print 'both right'
                        per += percent(new_sit, prob*Decimal(0.5), x, y, False, gems)        
                
                    new_sit = copy.deepcopy(situation)
                    final_loc = left_loc
                    while True:
                        test_loc = final_loc[0]-1, final_loc[1]-1
                        if test_loc[1] < 0:
                            break
                        if test_loc not in new_sit:
                            final_loc = test_loc[:]
                        else:
                            #print 'found in '
                            break
                    new_sit[final_loc] = None
                    #print 'left final', final_loc
                    if final_loc[0] ==x and final_loc[1] ==y:
                        per += prob*Decimal(0.5)
                    else:
                        hmm = percent(new_sit, prob*Decimal(0.5), x, y, False, gems)
                        per += hmm
                    return per
                
            else:
                y_loc += 2
    return 0
    

for case in xrange(int(f.readline())):
    num, x, y = map(int, f.readline().split())
    
    situation = {}
    answer = percent(situation, 1, x, y, False, num)
    print answer
    outfile.write("Case #%d: %0.7f\n" % (case+1, answer))
        





outfile.close()
f.close()
