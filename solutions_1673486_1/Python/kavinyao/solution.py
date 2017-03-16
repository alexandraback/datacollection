def minimal_expected_trial(A, B, probs):
    probs.append(1.0) # sentinel
    met = 1.0 + B + 1 # for press enter right away

    # now test for backspace (A-i) times and input
    correct_prob = 1.0
    for i in range(A+1):
        essential_ks = (A-i) + (B-i) + 1 #bs + retype + enter
        met_tmp = essential_ks*correct_prob + (essential_ks+B+1)*(1.0-correct_prob)
        if met_tmp < met:
            met = met_tmp
        correct_prob *= probs[i]

    return met

if __name__ == '__main__':
    import sys
    input_file_name = sys.argv[1]
    with open(sys.argv[1]) as input_file:
        cases_num = int(input_file.next())
        with open('result', 'wb') as output_file:
            for i in range(cases_num):
                print 'solving case %d' % i
                A, B = (int(x) for x in input_file.next().split(' '))
                probs = [float(x) for x in input_file.next().split(' ')]
                met = minimal_expected_trial(A, B, probs)
                output_file.write("Case #%s: %.6f\n" % (i+1, met))
