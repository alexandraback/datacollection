import sys

def solve(dishes):
    time = 0
    while dishes:
        dishPosition, maxDish = max(enumerate(dishes), key=lambda (pos, dish): dish)
        if maxDish == 1:
            # there's maximum 1 pancake at a plate left
            return time + 1
        if maxDish == 0:
            # everything's eaten
            break
        halfDish = maxDish / 2
        newDishes = [dish for (pos, dish) in enumerate(dishes) if pos != dishPosition] + [halfDish, maxDish - halfDish]
        newMaxDish = max(newDishes)
        if (maxDish - newMaxDish) >= 1:
            # we'll gain more than we'd lose, move the dishes
            dishes = newDishes
        else:
            # let the diners eat through
            dishes = [(dish - 1) for dish in dishes if dish > 1]
        time += 1
    return time

def solve1(dishes):
    time = 0
    while dishes:
        maxDish = max(dishes)
        if maxDish == 1:
            return time + 1
        if maxDish == 0:
            return time
        halfDish = maxDish / 2
        newMaxDish = max(halfDish, maxDish - halfDish)
        newDishes = []
        for dish in dishes:
            if dish <= newMaxDish:
                newDishes.append(dish)
            else:
                halfDish = dish / 2
                newDishes.extend((halfDish, dish - halfDish))
        newMaxDish = max(newDishes)
        operations = len(newDishes) - len(dishes)
        if maxDish - newMaxDish >= operations:
            # there is the gain in moving the dishes
            dishes = newDishes
            time += operations
        else:
            # let the diners eat
            dishes = [(dish - 1) for dish in dishes if dish > 1]
            time += 1

    return time

def trySplit(dishes, touchNplates, splitCount):
    maxDish = dishes[0]
    moveDish = maxDish / splitCount
    if touchNplates < len(dishes):
        resDish = max(moveDish, maxDish - moveDish * (splitCount - 1), dishes[touchNplates])
    else:
        resDish = max(moveDish, maxDish - moveDish * (splitCount - 1))
    return maxDish - resDish - touchNplates * (splitCount - 1)

def doSplit(dishes, touchNplates, splitCount):
    result = dishes[touchNplates:]
    for dish in dishes[:touchNplates]:
        moveDish = dish / splitCount
        result.extend([moveDish] * (splitCount - 1) + [dish - moveDish * (splitCount - 1)])
    return sorted(result, reverse=True)

def solve2(dishes):
    time = 0
    dishes = sorted(dishes, reverse=True)
    while True:
        if dishes[0] <= 2:
            return time + dishes[0]
        # let's find out if there's a need to split stuff
        split = []
        for splitCount in xrange(2, dishes[0]):
            split.extend([(trySplit(dishes, n + 1, splitCount), n + 1, splitCount)
                           for n in xrange(len(dishes))])
        maxSplit, maxN, splitCount = max(split, key=lambda(profit, n, count): profit)
        if maxSplit >= 0:
            if maxN > dishes[0]:
                print 'BUG'
                import pdb;pdb.set_trace()
            dishes = doSplit(dishes, maxN, splitCount)
            time += maxN * (splitCount - 1)
        else:
            break
            #continue

        # if we got here there would be no more splitting
    return time + dishes[0]
        #dishes = [(dish - 1) for dish in dishes if dish > 1]
        #time += 1

    #return time

def main(inFile):
    data = []
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            N = int(inp.readline().strip())
            dishes = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve2(dishes)))
            data.append((sorted(dishes, reverse=True), solve2(dishes)))
    data.sort(key=lambda (dishes, solution): solution, reverse=True)
    for entry in data:
        print entry[0], ':', entry[1]

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
