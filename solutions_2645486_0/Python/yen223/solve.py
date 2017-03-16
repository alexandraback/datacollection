import argparse
from collections import defaultdict
def solve(energy, R, values):
    '''
    Returns the solution 
    '''
    dp = defaultdict(lambda:(0,energy))
    E = energy
    print "R:", R
    print "Energy:", E
    for i, val in enumerate(values):
        print "Val:", val
        prev_max_energy = dp[(i-1, 0)]
        prev_max_gain = dp[(i-1,1)]

        #Maximize energy
        energy_max_energy = min(prev_max_energy[1] + R, energy) 
        energy_max_gain = min(prev_max_gain[1] + R, energy)
        if energy_max_gain >= energy_max_energy:
            max_energy = energy_max_gain
            prev = prev_max_gain
        else:
            max_energy = energy_max_energy
            prev = prev_max_energy
        if R + prev[1] <= E:
            use = 0
        else:
            use = min(R+prev[1]-E, prev[1])
        print "Energy use:", use
        dp[(i, 0)] = (prev[0] + use*val, max_energy)

        print "dp(i,0):", dp[(i,0)]

        #Maximize gain

        gain_max_energy = prev_max_energy[1] * val
        gain_max_gain = prev_max_gain[1] * val
        dp[(i, 1)] = (max(prev_max_energy[0] + gain_max_energy, 
                          prev_max_gain[0] + gain_max_gain)
                    , min(energy, R))
        
        print "dp(i,1):", dp[(i,1)]
    last = len(values) - 1
    return max(dp[last,0][0], dp[last,1][0])

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
        T = int(inp.readline())
        for idx in range(1, T+1):
            E, R, N = [int(x) for x in inp.readline().split()]
            values = [int(x) for x in inp.readline().split()]
            res = solve(E, R, values)
            sol = "Case #{}: {}".format(idx, res)
            print sol
            solutions.append(sol)
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
