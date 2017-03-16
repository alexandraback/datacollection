def calc_ans(E, R, weights):
    next_heigher = [0] * len(weights)
    for x in xrange(len(weights)):
        cur_weight = weights[x]
        ind = x + 1
        while ind < len(weights) and weights[ind] <= cur_weight:
            ind += 1
        next_heigher[x] = ind

    max_E = E
    cur_E = E
    ans = 0
    length = len(weights)
    for x in xrange(length):
        if next_heigher[x] == length:
            ans += weights[x] * cur_E
            cur_E = 0
        else:
            energy_to_heigher = cur_E + R * (next_heigher[x] - x)
            energy_rest = energy_to_heigher - max_E
            if energy_rest > 0:
                can_spend_energy = min(energy_rest, cur_E)
                ans += weights[x] * can_spend_energy
                cur_E -= can_spend_energy
        cur_E += R
    return ans


def main():
    filename = 'input_b.in'
    filename_out = 'output_b.txt'
    result_lines = []
    with open(filename, 'r') as input_file:
        t = int(input_file.readline())
        for test_case in xrange(1, t + 1):
            [E, R, N] = [int(x) for x in input_file.readline().split()]
            weights = [int(x) for x in input_file.readline().split()]
            R = min(R, E)
            ans = calc_ans(E, R, weights)
            line = 'Case #' + str(test_case) + ': ' + str(ans) + '\n'
            result_lines += [line]
    with open(filename_out, 'w') as output_file:
        output_file.writelines(result_lines)


main()
