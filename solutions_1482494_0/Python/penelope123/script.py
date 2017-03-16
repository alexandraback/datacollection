import sys
import operator

from string import maketrans   # Required to call maketrans function.

def main(raw_data):
    data = []
    for line in raw_data:
        data.append(line.strip())
        
    T = data.pop(0)
    for i in range(int(T)):
        num_levels = int(data.pop(0))
        levels = []
        for j in range(num_levels):
            a1, a2 = data.pop(0).split(' ')
            levels.append([int(a1), int(a2), 2])
            
        num_stars = 0
        count = 0
        while True:
            if not levels:
                break
            count += 1
            #print "count is",count
            #print "num_stars is", num_stars
            #finish a 2 star level if possible
            levels = sorted(levels, key=operator.itemgetter(1), reverse=True)
            levels = sorted(levels, key=operator.itemgetter(2), reverse=True)
            #print levels
            level_picked = False
            for j, level in enumerate(levels):
                if level[1] <= num_stars:
                    #print "picked",j, level
                    #use this for n stars
                    num_stars += level[2]
                    del(levels[j])
                    level_picked = True
                    break
            if level_picked:
                continue        
                    
            #otherwise, try for a one star level
            levels = sorted(levels, key=operator.itemgetter(0))
            levels = sorted(levels, key=operator.itemgetter(1), reverse=True)
            #levels = sorted(levels, key=operator.itemgetter(2))
            #print "resorted", levels
            for j, level in enumerate(levels):
                if level[2] == 2:
                    if level[0] <= num_stars:
                        #print "picked",j, level
                        #use this for 1 stars
                        num_stars += 1
                        levels[j][2] -= 1
                        if levels[j][2] == 0:
                            del(levels[j])
                        level_picked = True
                        break
            if not level_picked:
                count = 'Too Bad'
                break
                
        print "Case #%s: %s" %(i+1, count)
        
        
if __name__ == "__main__":
    main(sys.stdin)
