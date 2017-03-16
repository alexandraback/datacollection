t = int(raw_input().strip())

def get_missing_list(n, lists):
    freqs = {}
    for list in lists:
        for value in list:
            if value in freqs:
                freqs[value] = freqs[value] + 1
            else:
                freqs[value] = 1

    result = []
    for value in freqs:
        if freqs[value] % 2 ==1:
            result.append(value)

    result.sort()
    return result
#for each test case
for i in range(1, t + 1):
    n = int(raw_input().strip())

    #lists
    lists = []
    for j in range(0, 2*n-1):
        cur_list = [int(x) for x in raw_input().strip().split()]
        lists.append(cur_list)

    result = get_missing_list(n, lists)
    result_string = ''.join(str(x) + " " for x in result)

    print("Case #" + str(i) + ": " + result_string)

