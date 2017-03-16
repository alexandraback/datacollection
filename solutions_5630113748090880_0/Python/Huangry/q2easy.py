import math

with open ('B-small-attempt0.in', 'r') as f:
    with open ('q2solution.txt', 'w') as solution:
        t = int(f.readline())
        for case in range(t):
            N = int(f.readline())
            ls_papers = list()
            set_soldiers = set()
            for paper in range(2*N-1):
                line = [int(x) for x in f.readline().split()]
                for soldier in line:
                    if soldier in set_soldiers:
                        set_soldiers.remove(soldier)
                    else:
                        set_soldiers.add(int(soldier))
            missing = sorted(list(set_soldiers))
            answer = ''
            for i in missing:
                answer += str(i) + ' '

            solution.write('Case #' + str(case+1) + ': ' + answer[:-1] + '\n')

        solution.closed
    f.closed