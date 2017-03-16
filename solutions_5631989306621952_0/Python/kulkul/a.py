import itertools


def find_solution(chars):
    word = []
    for c in chars:
        if len(word) == 0:
            word.append(c)
            continue

        word_first = list(word)
        word_first.insert(0, c)
        word_last = list(word)
        word_last.append(c)
        if ''.join(word_first) > ''.join(word_last):
            word.insert(0, c)
        else:
            word.append(c)

    return ''.join(word)


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
    chars = input()

    solution = find_solution(chars)

    output_str = "Case #%d: %s" % (i + 1, solution)
    print(output_str)
    f.write(output_str + "\n")
