def find_solution(n, bffs):
    larsest_size = 0
    for i in range(n):
        start = i
        current = i
        size = 1
        current_selected = [i]
        while True:
            next = bffs[current] - 1
            if next in current_selected:
                if next == start or next == current_selected[-2]:
                    if next == current_selected[-2]:
                        while True:
                            found = False
                            for j in range(n):
                                if j not in current_selected:
                                    if bffs[j] - 1 == current:
                                        size += 1
                                        current_selected.append(j)
                                        current = j
                                        found = True
                                        break
                            if not found:
                                break
                    # print(current_selected)
                    larsest_size = max(larsest_size, size)
                break
            else:
                size += 1
                current_selected.append(next)
                current = next
        # print(current_selected)
        # larsest_size = max(larsest_size, size)
    return larsest_size

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
    bffs = [int(x) for x in input().split()]

    solution = find_solution(n, bffs)

    output_str = "Case #%d: %s" % (i + 1, solution)
    print(output_str)
    f.write(output_str + "\n")
