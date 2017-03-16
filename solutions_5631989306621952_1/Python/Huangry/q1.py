import math

with open ('A-large (8).in', 'r') as f:
    with open ('q1solution.txt', 'w') as solution:
        t = int(f.readline())
        for case in range(t):
            S = f.readline()
            best = ''
            front_letter = 'A'
            for letter in S:
                if letter >= front_letter:
                    best = letter + best
                    front_letter = letter
                else:
                    best = best + letter


            solution.write('Case #' + str(case+1) + ': ' + best)

        solution.closed
    f.closed