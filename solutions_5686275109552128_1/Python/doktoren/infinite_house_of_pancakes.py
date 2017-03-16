import sys

def solve(plates):
    best_solution = max(plates)
    divisors = [1 for _ in plates]
    value = lambda index: (divisors[index]+plates[index]-1)/divisors[index]
    num_divisions = 0
    while num_divisions < best_solution:
        num_divisions += 1
        index_to_divide = 0
        highest_value = value(0)
        for i in range(1, len(plates)):
            if value(i) > highest_value:
                highest_value = value(i)
                index_to_divide = i
        divisors[index_to_divide] += 1
        solution = num_divisions + max(value(i) for i in range(len(plates)))
        if solution < best_solution:
            #print "Better solution: {}".format(", ".join("{}/{}".format(plates[i], divisors[i]) for i in range(len(plates))))
            best_solution = solution
    return best_solution

with open(sys.argv[1], 'r') as f:
    t = int(f.readline().strip())
    for n in range(1, t+1):
        d = int(f.readline().strip())
        plates = [int(s) for s in f.readline().strip().split(" ")]
        print "Case #{}: {}".format(n, solve(plates))
