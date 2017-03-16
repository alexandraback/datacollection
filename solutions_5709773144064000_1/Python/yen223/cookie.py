import argparse

def solve(farm_cost, farm_roi, target):
    '''
    Returns the solution 
    '''
    time = 0
    num_cookies = 0
    curr_roi = 2
    if target <= farm_cost:
        return target / curr_roi

    time_with_farm = 0
    time_without_farm = 0
    while 1:
        # Get next checkpoint
        time_to_next_farm = farm_cost / curr_roi
        time_to_target_with_farm = target/(curr_roi+farm_roi)

        time_with_farm = time_to_next_farm + time_to_target_with_farm

        time_to_target = target / curr_roi
        time_without_farm = time_to_target

        # t_paid = farm_cost/(curr_roi+farm_roi)
        # time_with_farm = time_to_next_farm + t_paid

        # cookies_without_farm = curr_roi * time_with_farm + farm_cost
        # print cookies_without_farm
        if (time_with_farm < time_without_farm):
            time += time_to_next_farm
            curr_roi += farm_roi
        else:
            time += time_to_target
            break
            
        
            # Don't buy the farm


    return time


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        for idx in range(int(inp.readline())):
            farm_cost, farm_roi, target = [float(x) for x in inp.readline().split()]
            result = solve(farm_cost, farm_roi, target)
            solutions.append("Case #{0}: {1}".format(idx+1, result))
        
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
    else:
        print ('\n'.join(solutions))
