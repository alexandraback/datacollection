from sets import Set

def digits(number):
    r = []
    for digit in str(number):
        r.append(digit)
    return Set(r)

if __name__ == "__main__":
    data = []
    T = 0
    with open('/Users/mgalushka/google_code_jam/output1.out', 'w') as out:
        with open('/Users/mgalushka/google_code_jam/input1', 'r') as inp:
            T = int(inp.readline().strip())
            for case_number in range(1, T+1):
                N = int(inp.readline().strip())
                if N == 0:
                    print("Case #{0}: INSOMNIA".format(case_number))
                    out.write("Case #{0}: INSOMNIA\n".format(case_number))
                else:
                    result = N
                    all_numbers = []
                    all_numbers.append(N)
                    all_digits = Set(digits(N))
                    multiplier = 2
                    iterations = 0
                    insomnia = False
                    while len(all_digits) < 10:
                        result = multiplier * N
                        all_digits = all_digits.union(digits(result))
                        all_numbers.append(result)
                        multiplier += 1
                        iterations += 1
                        if iterations > 10000000:
                            print("Case #{0}: INSOMNIA".format(case_number))
                            out.write("Case #{0}: INSOMNIA".format(case_number))
                            insomnia = True
                    if not insomnia:
                        print("Case #{0}: {1} ({2})".format(case_number, result, "[{0}]".format(', '.join(map(lambda n: str(n), all_numbers)))))
                        out.write("Case #{0}: {1}\n".format(case_number, result))
                    else:
                        print("Case #{0}: INSOMNIA".format(case_number))
                        out.write("Case #{0}: INSOMNIA\n".format(case_number))
