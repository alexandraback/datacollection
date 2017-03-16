inputName = 'C-small-attempt2'

# Take input
infile = open(inputName + '.in', 'r')
lines = infile.readlines()
infile.close()

outfile = open(inputName + '-out.txt', 'w')

numTests = int(lines[0])
counter = 1
testNum = 1

while testNum <= numTests:
    # Parse input
    J, P, S, K = [int(x) for x in lines[counter].split()]
    print("J: %s , P: %s, S: %s, K: %s" % (J, P, S, K))
    result = ''

    if J * P * S <= J * P * K :
        print("run out of full combinations after %s days." % (J * P * S))
        result += str(J*P*S)
        # Just enumerate all combinations of  J * P * S
        for j_index in range(1,J+1):
            for p_index in range(1, P+1):
                for s_index in range(1, S+1):
                    result += '\n' + str(j_index) + ' ' + str(p_index) + ' ' + str(s_index)
    else:
        print("repeat J-P combinations too many times after %s days." % (J * P * K))
        result += str(J*P*K)
        s_index = 0
        inc_count = 0
        jsCombo = [[0 for col in range(S)] for row in range(J)]
        psCombo = [[0 for col in range(S)] for row in range(P)]

        # print(jsCombo)
        # print(psCombo)
        for j_index in range(1,J+1):
            for p_index in range(1, P+1):
                for k_index in range(1, K+1):
                    # Check for this J_S or P_S combination being used too many times
                    while jsCombo[j_index-1][s_index] >= K or psCombo[p_index-1][s_index] >= K:
                        s_index = (s_index + 1) % S
                    result += '\n' + str(j_index) + ' ' + str(p_index) + ' ' + str(s_index + 1)

                    # Add counters to this J_S and P_S combination
                    jsCombo[j_index-1][s_index] += 1
                    psCombo[p_index-1][s_index] += 1
                    # inc_count += 1
                    # if inc_count % S == 0:
                    #     s_index += 1
                    # s_index = (s_index + 1) % S

        # print(jsCombo)
        # print(psCombo)

    outfile.write('Case #' + str(testNum) + ': ' + result)
    if testNum < numTests:
        outfile.write('\n')

    testNum += 1
    counter += 1

outfile.close()
