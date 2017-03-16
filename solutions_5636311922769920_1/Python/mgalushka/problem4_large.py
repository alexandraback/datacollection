import math

if __name__ == "__main__":
    data = []
    T = 0
    with open('/Users/mgalushka/google_code_jam/output4_large.out', 'w') as out:
        with open('/Users/mgalushka/google_code_jam/input4_large', 'r') as inp:
            T = int(inp.readline().strip())
            for case_number in range(1, T+1):
                line = inp.readline().strip().split(' ')
                K = int(line[0])
                C = int(line[1])
                S = int(line[2])
                min_possible = int(math.ceil(1.0 * K / C))
                if S < min_possible:
                    print("Case #{0}: IMPOSSIBLE".format(case_number, result))
                    out.write("Case #{0}: IMPOSSIBLE\n".format(case_number))
                    continue
                else:
                    result = ''
                    for it in range(1,min_possible+1):
                        next_position = (it-1)*C + 1
                        j = min(C-1, K-1)
                        while j >= 1:
                            multiplier = ((it-1)*C)+j
                            if multiplier >= K:
                                multiplier = K-1
                            next_position += multiplier * pow(K, j)
                            j -= 1
                        if it == min_possible:
                            result += str(next_position)
                        else:
                            result += str(next_position) + ' '
                    print("Case #{0}: {1}".format(case_number, result))
                    out.write("Case #{0}: {1}\n".format(case_number, result))
                    
