import fileinput
import math

#Note: did small manual output fix,

results_map = eval(file("map_20_all_accurate.txt","r").read())

MAX_DIAMONDS = 20

MAX_DIM_X = MAX_DIAMONDS*2
MAX_DIM_Y = MAX_DIAMONDS/2

RESOLUTION = 100000000.

possible_vals = [0] + reduce(lambda x,y:x+y,[[y/(2.**x) for x in range(30)] for y in range(1,30)], [])
#print possible_vals
max_dist = 0
bad_val = 0
guess = 0

for i in range(MAX_DIAMONDS):
    for y in range(MAX_DIM_Y):
        for x in range(MAX_DIM_X):
            target = (results_map[i][y][x]/RESOLUTION)
            min_distance = 10
            optimal_val = 0
            for v in possible_vals:
                dist = math.fabs(target-v)
                if dist < min_distance:
                    #print "min dist",dist,v,target
                    min_distance = dist
                    optimal_val = v
            #print "Changing",target,"to",optimal_val
            if min_distance > max_dist:
                max_dist = min_distance
                bad_val = target
                guess = optimal_val
            results_map[i][y][x] = optimal_val
                
#print "Max dist is:",max_dist,bad_val,guess


def solve_params(num,x,y):
    x += MAX_DIAMONDS
    if x < 0 or x >= MAX_DIM_X:
        return 0
    if y < 0 or y >= MAX_DIM_Y:
        return 0
    return results_map[num][y][x]

def main():
    it = fileinput.input()
    it.next()
    for i,l in enumerate(it):
        num,x,y = [int(x) for x in l.split()]
        print "Case #%d: %f" % (i+1,solve_params(num,x,y))

if __name__ == "__main__":
    main()
    
