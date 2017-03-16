#10:20

def counting_sheep(N):
    if N == 0:
        return False

    exist_digits = set()
    count = 1
    while count < 10000:
        current_value = count*N
        exist_digits = exist_digits.union(set(str(current_value)))
        if(len(exist_digits) == 10):
            return current_value
        count += 1
    return False

def counting_sheep_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        last_count = counting_sheep(int(raw_input()))
        if last_count == False:
            print 'Case #%s: INSOMNIA' % test_case
        else:
            print 'Case #%s: %s' % (test_case, last_count)


def pancakes(S):
    reverse_count = 0
    last_side = S[0]
    for current_side in S[1:]:
        if last_side == current_side:
            continue
        else:
            reverse_count += 1
            last_side = current_side
    if S[-1] == '-':
        reverse_count += 1
    return reverse_count


def pancakes_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        print 'Case #%s: %s' % (test_case, pancakes(raw_input()))

pancakes_in()