def find_solution(n):
    numbers = {}
    odd_numbers = []
    for i in range(2 * n - 1):
        line_numbers = [int(x) for x in input().split()]
        for j in line_numbers:
            if j in numbers:
                numbers[j] = numbers[j] + 1
            else:
                numbers[j] = 1

    # print(numbers)

    for i in list(numbers.keys()):
        if numbers[i] % 2 == 1:
            odd_numbers.append(i)

    odd_numbers.sort()
    return ' '.join([str(x) for x in odd_numbers])

def test():
    print("start test")
    test_cases = [
        [[2, 3, 2], [1, 2]],
        [[1, 1, 1], [1]],
        [[2, 1, 1], [-1]],
        [[2, 1, 2], [1, 2]],
        [[3, 2, 3], [1, 2, 3]],
        [[28, 3, 28], [1, 2, 3]],
        # [[10, 2, 10], [1, 12, 23, 34, 45, 56, 67, 78, 89, 100]]
    ]
    solution = []
    try:
        for test_case in test_cases:
            solution = find_solution(test_case[0][0], test_case[0][1], test_case[0][2])
            assert solution == test_case[1]
            print("pass")
    except Exception as e:
        print("fail")
        print(test_case[0][0], test_case[0][1], test_case[0][2], test_case[1], solution)
        raise e

    print("end test")


# test()

f = open('output.txt', 'w')

t = int(input())

for i in range(t):
    n = int(input())

    solution = find_solution(n)

    output_str = "Case #%d: %s" % (i + 1, solution)
    print(output_str)
    f.write(output_str + "\n")
