def print_case_result(case_num, result):
    print "Case #" + str(case_num) +": " + str(result)


def count_flips(pancakes, cur, happy_count, blank_count):
    if cur == len(pancakes):
        return 
    if pancakes[cur] == '+':
        happy_count[cur] = happy_count[cur - 1]
        byhappy = happy_count[cur - 1] + 1
        byblank = blank_count[cur - 1] + 2
        blank_count[cur] = byblank if byblank < byhappy else byhappy
    else:
        blank_count[cur] = blank_count[cur - 1]
        byhappy = happy_count[cur - 1] + 2
        byblank = blank_count[cur - 1] + 1
        happy_count[cur] = byblank if byblank < byhappy else byhappy
    count_flips(pancakes, cur + 1, happy_count, blank_count)


if __name__ == '__main__':
    testcase_num = int(raw_input())
    for case_num in range(1, testcase_num+1):
        pancakes = raw_input().strip()
        flips_count = [None] * len(pancakes)
        blank_count = [None] * len(pancakes)
        flips_count[0] = 0 if pancakes[0] == '+' else 1
        blank_count[0] = 1 if pancakes[0] == '+' else 0
        count_flips(pancakes, 1, flips_count, blank_count)
        print_case_result(case_num, flips_count[-1])