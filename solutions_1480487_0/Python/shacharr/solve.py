import fileinput
import psyco
psyco.full()

epsilon = 1E-12


def calc_score(ji, x, yi):
    return ji+x*yi

def min_score_to_avoid_elimination(weight,x,competing_score):
    return (competing_score - weight)/x

def is_safe(ji, x, yi, weights):
    my_score = calc_score(ji, x, yi)
    total_yis = yi
    for w in sorted(weights):
        total_yis += min_score_to_avoid_elimination(w,x,my_score)
        if total_yis >= 1:
            return True
    return False

def search_optimal_weight(i,x,weights):
    weights_minus_me = weights[:i] + weights[i+1:]
    ji = weights[i]
    bottom = 0.0
    top = 1.0
    #print "Checking for",i,"others are",weights_minus_me
    while top - bottom > epsilon:
        mid = (top+bottom)/2
        if is_safe(ji,x,mid,weights_minus_me):
            top = mid
        else:
            bottom = mid
    return (top+bottom)/2

def solve_weights(weights):
    x = float(sum(weights))
    return [search_optimal_weight(i,x,weights)*100 for i in range(len(weights))]

def main():
    it = fileinput.input()
    num_cases = it.next()
    for i,l in enumerate(it):
        res = solve_weights([int(x) for x in l.split()[1:]])
        print "Case #%d:" % (i+1),
        for i in res:
            if i < (epsilon*1000):
                print 0,
            else:
                print i,
        print ""

#print solve_weights([20,10])
#print solve_weights([10,0])
#print solve_weights([25,25,25,25])
#print solve_weights([24,30,21])

if __name__ == "__main__":
    main()
