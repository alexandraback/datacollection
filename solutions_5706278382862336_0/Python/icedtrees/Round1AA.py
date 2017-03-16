numLines = raw_input()
for case in range(1, int(numLines) + 1):
    fraction = raw_input()
    numerator, denominator = fraction.split("/")
    numerator, denominator = int(numerator), int(denominator)
    currentTry = 1
    generations = 0
    
    while True:
        newNumerator = denominator / currentTry
        if newNumerator <= numerator:
            break
        currentTry *= 2
        generations += 1
    
    if denominator & (denominator - 1) != 0:
        result = "impossible"
    else:
        result = str(generations)
    
    # print fraction
    print "Case #{}: {}".format(case, result)