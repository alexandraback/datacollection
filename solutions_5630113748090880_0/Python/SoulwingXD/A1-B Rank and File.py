num_tests = int(input())
for test in range(num_tests):
    n = int(input())
    lists = [tuple(map(int, input().split())) for x in range(2 * n - 1)]
    nums = dict()
    for n in [num for tup in lists for num in tup]:
        if n not in nums.keys():
            nums[n] = 1
        else:
            nums[n] += 1
    result = ' '.join(list(map(str, sorted([x for x, y in nums.items() if y % 2 == 1]))))
    print('Case #{}: {}'.format(test + 1, result))
