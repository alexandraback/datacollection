def main():
    cases = int(raw_input())
    for case in range(1, cases + 1):
        #do stuff
        kidTotal = int(raw_input())
        bffs = [int(section) - 1 for section in raw_input().split(" ")]
        isLooped = [False] * kidTotal
        longestLoop = 0
        doubles = []
        for x in range(kidTotal):
            soFar = set()
            order = []
            if isLooped[x]:
                continue
            else:
                current = x
                last = 0
                while not current in soFar:
                    soFar.add(current)
                    order.append(current)
                    last = current
                    current = bffs[current]
                if current == x:
                    for person in soFar:
                        isLooped[person] = True
                    if len(soFar) == 2:
                        doubles.append((current, last))
                    if longestLoop < len(soFar):
                        longestLoop = len(soFar)
        doubleLengths = []
        carried = [[0] for o in range(kidTotal)]
        bestCarry = []
        for x in range(kidTotal):
            current = x
            total = 0
            while isLooped[current] == False:
                total += 1
                current = bffs[current]
            carried[current].append(total)
        for x in carried:
            bestCarry.append(max(x))
        for dub in doubles:
            one, two = dub
            total = bestCarry[one] + bestCarry[two] + 2
            doubleLengths.append(total)
        doubleTotal = sum(doubleLengths)
        longest = longestLoop
        if longest < doubleTotal:
            longest = doubleTotal
            
        print "CASE #%s: %s" % (case, longest)

main()