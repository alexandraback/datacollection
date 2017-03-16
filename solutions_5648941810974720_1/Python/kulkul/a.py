def find_solution(string):
    num_to_str = ["ZERO", "TWO", "SIX", "EIGHT", "FOUR", "FIVE", "SEVEN", "THREE", "NINE",  "ONE"]
    str_to_map = {"ZERO":0, "ONE":1, "TWO":2, "THREE":3, "FOUR":4, "FIVE":5, "SIX":6, "SEVEN":7, "EIGHT":8, "NINE":9}
    digits = []
    while True:
        for i in range(len(num_to_str)):
            digit_str = num_to_str[i]
            for j in digit_str:
                has_digit = True
                if j not in string:
                    has_digit = False
                    break
            if has_digit:
                digits.append(str_to_map[digit_str])
                for j in digit_str:
                    string = string.replace(j, '', 1)
                break
            # print(digits)
            # print(string)
        if string == '':
            break
    digits.sort()
    solution = [str(x) for x in digits]
    return ''.join(solution)

def test():
    print("---Start Test---")

    test_cases_in = [
        'OZONETOWER',
        'WEIGHFOXTOURIST',
        'OURNEONFOE',
        'ETHER',
    ]
    test_cases_out = [
        '012',
        '2468',
        '114',
        '3',
    ]

    for i in range(len(test_cases_in)):
        solution = find_solution(test_cases_in[i])
        try:
            assert (solution == test_cases_out[i])
        except:
            print("%d : expected %s, but actual %s" %
                  (i, test_cases_out[i], solution))

    print("---End Test---")

# test()

T = int(input())

for t in range(T):
    solution = find_solution(input())

    output_text = "Case #{}: {}".format(t + 1, solution)
    print(output_text)
