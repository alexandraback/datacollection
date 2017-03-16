def read_input(path):
    data = []
    with open(path, 'r') as inp:
        for line in inp:
            data.append(line.strip())
    return data

def write_result(outpath, result):
    with open(outpath, 'w') as out:
        for r in result:
            out.write('Case#1: {0}\n'.format(r))

def main():
    pass

if __name__ == "__main__":
    data = []
    T = 0
    with open('/Users/mgalushka/google_code_jam/output4_small.out', 'w') as out:
        with open('/Users/mgalushka/google_code_jam/input4', 'r') as inp:
            T = int(inp.readline().strip())
            for case_number in range(1, T+1):
                line = inp.readline().strip().split(' ')
                K = int(line[0])
                C = int(line[1])
                S = int(line[2])
                if K == S:
                    result = ''
                    for it in range(1, K+1):
                        if it == K:
                            result += str(it)
                        else:
                            result += str(it) + ' '
                    print("Case #{0}: {1}".format(case_number, result))
                    out.write("Case #{0}: {1}\n".format(case_number, result))
                else:
                    print("Case #{0}: IMPOSSIBLE".format(case_number, result))
                    out.write("Case #{0}: IMPOSSIBLE\n".format(case_number))
