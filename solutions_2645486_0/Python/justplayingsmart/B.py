##input = open('B-sample-input.txt', 'r')
##output = open('B-sample-output.txt', 'w')

input = open('B-small-attempt0.in', 'r')
output = open('B-small.out', 'w')

##input = open('B-large.in', 'r')
##output = open('B-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]


def solve(E, R, N, values, current_energy):
##    print 'N=', 'values', values, 'curr energy=', current_energy
    if N == 1:
##        print 'returning', current_energy * values[0]
        return current_energy * values[0]
    min_energy = max(current_energy + R - E, 0)
    gains = []
    for expend in range(min_energy, current_energy + 1):
##        print 'curr energy=', current_energy, 'expending', expend
        next_energy = current_energy + R - expend
##        print 'energy for next round =', next_energy
        gain = (expend * values[0] + solve(E, R, N-1, values[1:], next_energy))
##        print 'gain =', gain
        gains.append(gain)
    return max(gains)

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        E, R, N = read_ints()
        values = read_ints()
##        if case == 1:
        solution = solve(E, R, N, values, E)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
