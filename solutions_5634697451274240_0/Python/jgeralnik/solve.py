def solve(pancakes):
    result = 0
    pancakes = pancakes.rstrip("+")
    for i in xrange(len(pancakes) - 1):
        if pancakes[i] != pancakes[i+1]:
            result += 1
    if pancakes:
        if result % 2 == 0:
            result += int(pancakes[0] == '-')
        else:
            result += int(pancakes[0] == '+')
    return result

T = int(raw_input())
for i in xrange(1, T+1):
    pancakes = raw_input()
    solution = solve(pancakes)
    print "Case #%i:" % i, solution
