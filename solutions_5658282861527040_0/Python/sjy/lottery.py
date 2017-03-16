from jam import jam

# jam.startDebugging()

# parse input
jam.read('B-small-attempt0.in')
numCases = int(jam.state.pop(0))
cases = []
for _ in range(numCases):
    a, b, k = jam.state.pop(0).split(" ")
    cases.append((int(a), int(b), int(k)))

for i, case in enumerate(cases):
    jam.debug(case)
    a, b, k = case
    
    wins = (x&y for x in range(a) for y in range(b) if x&y < k)
    result = sum(1 for x in wins)

    print "Case #{}: {}".format(i+1, result)
    jam.debug('')
