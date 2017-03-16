import argparse
from collections import deque
def solve(naomi, ken):
    '''
    Returns the solution 
    '''

    def play_as_ken(told_n, ken):
        # print "Ken:", ken
        for idx, x in enumerate(ken):
            if x > told_n:
                print "Ken played {} against {}, ken scores.".format(x, told_n)
                ken.remove(x)
                return 0, ken
        else:
            x = ken.popleft()
            print "Ken played {} against {}, naomi scores.".format(x, told_n)
            return 1, ken

    def play_war(naomi, ken):
        print "Playing normal."
        print "Ken:",ken
        print "Naomi:",naomi
        ken_score = 0
        naomi_score = 0
        ken = deque(sorted(ken))
        naomi = sorted(naomi)
        while naomi:
            p_n = naomi.pop()
            # print "Naomi played {}".format(p_n)
            score, ken = play_as_ken(p_n, ken)
            naomi_score += score
            # print naomi_score
        return naomi_score

    def play_deceitful_war(naomi, ken):
        print "Playing deceit."
        ken_score = 0
        ken = deque(sorted(ken))
        # print ken
        naomi = deque(sorted(naomi))
        # print naomi
        naomi_score = 0
        print "Ken:",ken
        print "Naomi:",naomi
        while naomi:
            # if len([1 for x in ken if naomi[0] < x]) == 0:
                # for n in naomi:
                #     if n > ken[-1]:
                #         p_n = n
                #         naomi.remove(p_n)
                #         break
            if naomi[0] > ken[0]:
                p_n = naomi.popleft()
                told_n = ken[-1] + 0.000001
            else:
                p_n = naomi.popleft()
                told_n = ken[-1] - 0.000001

            score, ken = play_as_ken(told_n, ken)   
            naomi_score +=  score
        return naomi_score       

    result = play_deceitful_war(naomi[:], ken[:]), play_war(naomi[:], ken[:])
    return result


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
            n = int(inp.readline())
            naomi = [float(x) for x in inp.readline().split()]
            ken = [float(x) for x in inp.readline().split()]
            resultA, resultB = solve(naomi, ken)
            solutions.append("Case #{0}: {1} {2}".format(idx+1, resultA, resultB))

    print '\n'.join(solutions)
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
