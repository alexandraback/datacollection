from operator import itemgetter


def solve(N, levels):
    rating = 0
    played = 0
    set1 = set()
    set2 = set()
    sorted1 = sorted(levels, key=itemgetter(1))
    sorted2 = sorted(levels, key=itemgetter(2))
    for count in range(len(levels)*2+1):
        if len(set2) == len(levels):
            return played
        if len(sorted2) > 0 and sorted2[0][2] <= rating and sorted2[0][0] not in set2:
            if sorted2[0][0] in set1:
                rating += 1
            else:
                rating += 2
            set2.add(sorted2[0][0])
            set1.add(sorted2[0][0])
            played += 1
            sorted2 = sorted2[1:]
        elif len(sorted1) > 0 and sorted1[0][1] <= rating and sorted1[0][0] not in set1:
            set1.add(sorted1[0][0])
            rating += 1
            played += 1
            sorted1 = sorted1[1:]
            
    return "Too Bad"



inp = raw_input()
T = int(inp)
for t in range(1,T+1):
    inp = raw_input()
    N = int(inp)
    levels = []
    for i in range(1,N+1):
        inp = raw_input()
        a, b = map(int,inp.split(' '))
        levels.append([i, a, b])
    answer = solve(N, levels)
    print "Case #" + str(t) + ": " + str(answer)
