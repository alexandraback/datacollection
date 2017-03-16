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
    with open('/Users/mgalushka/google_code_jam/output2.out', 'w') as out:
        with open('/Users/mgalushka/google_code_jam/input2.in', 'r') as inp:
            T = int(inp.readline().strip())
            for case_number in range(1, T+1):
                combination = inp.readline().strip()
                print(combination)

                last_sign = combination[-1]

                # previous character - we calculate number of changes of sign
                prev_s = None
                changes = 0
                for s in combination:
                    if prev_s:
                        if prev_s == s:
                            continue
                        else:
                            changes += 1
                    prev_s = s
                last_change = 1 if last_sign == '-' else 0

                result = changes + last_change
                print("Case #{0}: {1}".format(case_number, result))
                out.write("Case #{0}: {1}\n".format(case_number, result))
