import math

o = open("C:\Users\ANTON\Downloads\D-small-attempt0.in")
w = open("C:\Users\ANTON\PycharmProjects\CodeJam\Fractiles\Small-Output.txt", 'w')

input_lines = [i.strip('\n') for i in o]

cases = input_lines.pop(0)

for case_number, case in enumerate(input_lines):
    lol = case.split(' ')
    print lol
    K, C, S = int(lol[0]), int(lol[1]), int(lol[2])
    print K, C, S
    positions = range(K)
    if int(math.ceil(float(K) / float(C))) > S:
        solution = "IMPOSSIBLE"
    elif S >= K ** C:
        solution = [str(x+1) for x in positions]
    else:
        indexes = []
        while positions:
            index = 0
            if len(positions) > C:
                for i in reversed(range(C)):
                    index += (K ** i) * positions.pop(0)
            else:
                temp = 0
                for i in reversed(range(C)):
                    if positions:
                        temp = positions.pop(0)
                    index += (K ** i) * temp

            indexes.append(str(index + 1))
        solution = indexes

    final = solution
    if solution != "IMPOSSIBLE":
        final = ' '.join(solution)
    w.write("Case #" + str(case_number + 1) + ": " + final + '\n')
