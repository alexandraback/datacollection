num_tests = int(input())
for test in range(num_tests):
    s = input()
    result = s[0]
    for l in s[1:]:
        if l < result[0]:
            result += l
        else:
            result = l + result
    print('Case #{}: {}'.format(test + 1, result))
